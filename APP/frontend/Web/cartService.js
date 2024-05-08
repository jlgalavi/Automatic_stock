function agregarCarrito(producto){
    const memoria = JSON.parse(localStorage.getItem("cajas"));
    if(!memoria){
        const nuevoProducto = producto;
        nuevoProducto.cantidad = 1;
        localStorage.setItem("cajas", JSON.stringify([nuevoProducto]));
    }
}