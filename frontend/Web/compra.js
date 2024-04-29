//POST PEDIDO
document.getElementById('buy-cart').addEventListener('click', async () => {

    allProducts = allProducts.map(product => {
        let newProduct = {...product};
        delete newProduct.image;
        return newProduct;
    });
    
    const res = await fetch('http://localhost:4000/pedido', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify([allProducts]),
    });
});