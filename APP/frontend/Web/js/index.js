var swiper = new Swiper('.mySwiper-1', {
    slidesPerView: 1,
    spaceBetween: 30,
    loop: true,
    pagination: {
        el: '.swiper-pagination',
        clickable: true,
    },
    navigation: {
        nextEl: '.swiper-button-next',
        prevEl: '.swiper-button-prev',
    },

});

var swiper = new Swiper('.mySwiper-2', {
    slidesPerView: 1,
    spaceBetween: 30,
    loop: true,
    pagination: {
        el: '.swiper-pagination',
        clickable: true,
    },
    navigation: {
        nextEl: '.swiper-button-next',
        prevEl: '.swiper-button-prev',
    },
    breakpoints: {
        0: {    
            slidesPerView: 1,
        },
        520: {  
            slidesPerView: 2,
        },
        950: {
            slidesPerView: 3,
        },
    }

});

var swiper = new Swiper('.mySwiper-3', {
    slidesPerView: 1,
    spaceBetween: 30,
    loop: true,
    pagination: {
        el: '.swiper-pagination',
        clickable: true,
    },
    navigation: {
        nextEl: '.swiper-button-next',
        prevEl: '.swiper-button-prev',
    },
    breakpoints: {
        0: {    
            slidesPerView: 1,
        },
        520: {  
            slidesPerView: 2,
        },
        950: {
            slidesPerView: 3,
        },
    }

});

const containerProducts = document.getElementById('cont-products');

function showProductsList(productos) {
    productos.forEach(producto => {
        const newProduct = document.createElement("div");
        newProduct.classList.add('swiper-slide');
        newProduct.innerHTML = `
            <div class="product">
                <img src="${producto.img}" alt=""> 
                <div class="product-txt">
                    <h3>${producto.title}</h3>
                    <p>${producto.size} cm</p>
                    <p class="price">${producto.price}€</p>
                    <button class="btn-add-cart" data-id="${producto.id}">Agregar al carrito</button>
                </div>
            </div>
            `
        containerProducts.appendChild(newProduct);
        newProduct.getElementsByTagName("button")[0].addEventListener('click', () => addCart(producto)) });
   
}

showProductsList(products);

