const url = "ws://broker.emqx.io:8083/mqtt"
var client = mqtt.connect(url);

function eventoConectar(){
    client.subscribe("alberto", function(err){
        if(!err){
            client.publish("alberto", "hi there!");
        }
    });
}

function eventoMensaje(topic, message){
    console.log(message.toString());
    client.end();
}

client.on("connect", eventoConectar);

document.getElementById('buy-cart').addEventListener('click', async () => {

    allProducts = allProducts.map(product => {
        //PARA NO GUARDAR LA IMAGEN EN LA BBDD
        let newProduct = {...product};
        delete newProduct.image;
        return newProduct;
    });

    client.on("connect", eventoConectar);
    client.on("message", eventoMensaje);
});