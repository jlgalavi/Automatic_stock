#include <Arduino.h>
#include "src/quirc/quirc.h"
#include "esp_camera.h"
#include "Config.h"
// creating a task handle
TaskHandle_t QRCodeReader_Task; 
/*  Variables declaration */
struct QRCodeData
{
  bool valid;
  int dataType;
  uint8_t payload[1024];
  int payloadLen;
};

struct quirc *q = NULL;
uint8_t *image = NULL;  
camera_fb_t * fb = NULL;
struct quirc_code code;
struct quirc_data data;
quirc_decode_error_t err;
struct QRCodeData qrCodeData;  
String QRCodeResult = "";

/* VOID SETTUP() */
void setup_QR() {
  // Disable brownout detector.
  //WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);

  /* Init serial communication speed (baud rate). */
 Serial.begin(115200);
  /* Camera configuration. */
  Serial.println("Start configuring and initializing the camera...");
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 10000000;
  config.pixel_format = PIXFORMAT_GRAYSCALE;
  config.frame_size = FRAMESIZE_QVGA;
  config.jpeg_quality = 15;
  config.fb_count = 1;
  
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    ESP.restart();
  }
  
  sensor_t * s = esp_camera_sensor_get();
  s->set_framesize(s, FRAMESIZE_QVGA);
  
  Serial.println("Configure and initialize the camera successfully.");
  Serial.println();
  
  xTaskCreatePinnedToCore(QRCodeReader, "QRCodeReader_Task", 10000, NULL, 1, &QRCodeReader_Task, 0);
}
/* The function to be executed by "QRCodeReader_Task" */
// This function is to instruct the camera to take or capture a QR Code image,
// then it is processed and translated into text.
void QRCodeReader( void * pvParameters ){
  Serial.println("QRCodeReader is ready.");
  Serial.print("QRCodeReader running on core ");
  Serial.println(xPortGetCoreID());
  Serial.println();

  /* Loop to read QR Code in real time. */
  while(1){
      q = quirc_new();
      if (q == NULL){
        //enviarMensajePorTopic(CONTROL,"can't create quirc object\r\n" );
        Serial.print("can't create quirc object\r\n");  
        continue;
      }
    
      fb = esp_camera_fb_get();
      if (!fb)
      {
        Serial.println("Camera capture failed");
        //enviarMensajePorTopic(HELLO_TOPIC,"Camera capture failed" );
        continue;
      }   
      
      quirc_resize(q, fb->width, fb->height);
      image = quirc_begin(q, NULL, NULL);
      memcpy(image, fb->buf, fb->len);
      quirc_end(q);
      
      int count = quirc_count(q);
      if (count > 0) {
        quirc_extract(q, 0, &code);
        err = quirc_decode(&code, &data);
    
        if (err){
          //enviarMensajePorTopic(HELLO_TOPIC,"Decoding FAILED");
          Serial.println("Decoding FAILED");
          QRCodeResult = "Decoding FAILED";
        } else {
          //enviarMensajePorTopic(HELLO_TOPIC,"Decoding successful:\n");
          Serial.printf("Decoding successful:\n");
          dumpData_bis(&data);
        } 
        Serial.println();
      } 
      
      esp_camera_fb_return(fb);
      fb = NULL;
      image = NULL;  
      quirc_destroy(q);
  }
  delay(10);//mirar si funciona sin o si es necesario
}

/* Function to display the results of reading the QR Code on the serial monitor. */
void dumpData_bis(const struct quirc_data *data)
{
  Serial.printf("Version: %d\n", data->version);
  Serial.printf("ECC level: %c\n", "MLHQ"[data->ecc_level]);
  Serial.printf("Mask: %d\n", data->mask);
  Serial.printf("Length: %d\n", data->payload_len);
  Serial.printf("Payload: %s\n", data->payload);
  //MQTT
  QRCodeResult = (const char *)data->payload; //lee el valor del sensor ldr
 
  StaticJsonDocument<200> doc; //crea el mensaje en formato json
  doc["ID_BOX"] = QRCodeResult;
  String state_json;
  serializeJson(doc, state_json);
  enviarMensajePorTopic(CONTROLBOX_TOPIC,state_json);
}