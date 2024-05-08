const containerProducts = document.getElementById('cont-products');

function showProducts() {
    const productos = JSON.parse(localStorage.getItem("products"));
    if (productos) {
        productos.forEach(producto => {
           const newProduct = document.createElement("div");
            newProduct.classList.add('container-products');
            newProduct.innerHTML = `
                    <img src="${producto.img}" alt="">
                    <div class="product-text">
                        <h3>${producto.title}</h3>
                        <p class="price">${producto.price}€</p>
                        <div class="mod-products">
                            <button class="less">-</button>
                            <span class="quantity">${producto.quantity}</span>
                            <button class="more">+</button>
                      </div>
                    </div>
            `;
//            containerProducts.appendChild(newProduct);
//             newProduct.getElementsByTagName("button")[0].addEventListener('click', (e) => {
//                 quitCart(producto);
//                 showProducts();
//             });
//             newProduct.getElementsByTagName("button")[1].addEventListener('click', (e) => {
//                 addCart(producto)});
            
            
        });
//     } else {
//         const newProduct = document.createElement("div");
//         newProduct.classList.add('container-products');
//         newProduct.innerHTML = `
//             <h3>No hay productos en el carrito</h3>
//         `;
//         containerProducts.appendChild(newProduct);        
    }
}

showProducts();

// Path: APP/frontend/Web/js/carrito.js