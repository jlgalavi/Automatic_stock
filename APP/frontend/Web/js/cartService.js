function addCart(producto){
    const memory = JSON.parse(localStorage.getItem("products"));
    console.log(memory);
    if(!memory){
        const newProduct = getNewProductForMemory(producto);
        localStorage.setItem("products", JSON.stringify([newProduct]));
    } else {
        const indexproduct = memory.findIndex(product => product.id === producto.id);
        const newMemory = memory;
        if(indexproduct === -1)
        {
            newMemory.push(getNewProductForMemory(producto)); 
        }
        else
        {
            newMemory[indexproduct].quantity ++;
        }
        localStorage.setItem("products", JSON.stringify(newMemory));
    }
    updateNumberCart();
}

function quitCart(producto){
    const memory = JSON.parse(localStorage.getItem("products"));
    const indexproduct = memory.findIndex(product => producto.id === product.id);
    if(memory[indexproduct].quantity > 1){
        memory[indexproduct].quantity --;
    } else {
        memory.splice(indexproduct, 1);
    }
    localStorage.setItem("products", JSON.stringify(memory));
    updateNumberCart();
}

// Añadir cantidad de producto
function getNewProductForMemory(producto){
    const newProduct = producto;
    newProduct.quantity = 1;
    return newProduct;
}

const countCart = document.querySelector('.cart-count');
function updateNumberCart(){
    const memory = JSON.parse(localStorage.getItem("products"));
    const elementsQuantity = memory.reduce((acc, current) => acc + current.quantity, 0);
    countCart.innerText = elementsQuantity;
}

updateNumberCart();