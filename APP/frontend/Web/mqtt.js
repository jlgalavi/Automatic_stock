const url = "ws://broker.emqx.io:8083/mqtt"
var client = mqtt.connect(url);

document.getElementById('buy-cart').addEventListener('click', async () =>{

    allProducts = allProducts.map(product => {
        //PARA NO GUARDAR LA IMAGEN EN LA BBDD
        let newProduct = {...product};
        delete newProduct.image;
        return newProduct;
    });

    client.on('connect', function () {
        client.subscribe('alberto', function (err) {
            if (!err) {
                client.publish('alberto', 'juana', function(err) {
                    if(err) {
                        console.log("Error al publicar el mensaje", err);
                    }
                });
            } 
            else{
                console.log("Error al suscribirse al topic", err);
            }
        });
    });
    
    client.on('error', function (err) {
        console.log('Error de conexión MQTT:', err);
    });
    //client.on('connect', eventoConectar);
    //client.on('message', eventoMensaje);
});

