long now, lastMsg = 0;
long sensorsUpdateInterval = 5000; // tiempo de actualización de los sensores

void on_loop() {

  now = millis();
  if (now - lastMsg > sensorsUpdateInterval ) {
    lastMsg = now;
    //
    // Read and process sensors
    //

  }
  //ejecuta las funciones de leer la camaraqr, observar si el boton esta pulsado y si las luces se apagan
  //readbutton(); 
  cameraqr();
  //ilumination();
}

