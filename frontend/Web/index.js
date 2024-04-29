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

const cartInfo = document.querySelector('.cart-menu');
const rowProducts = document.querySelector('#cart-list');
const productsList = document.querySelector('#products-list');

let allProducts = [];
let cartCount = 0;

const valorTotal = document.querySelector('.total-price');
const btnBuyCart = document.querySelector('.btn-buy-cart');
const updateCartValue = document.getElementsByClassName('cart-count');

productsList.addEventListener('click', (e) => {
    if(e.target.classList.contains('btn-add-cart')) {
        const product = e.target.parentElement.parentElement;
        cartCount++;
        updateCartValue[0].innerText = cartCount; 
        const productInfo = 
        {
            image: product.querySelector('img').src,
            title: product.querySelector('h3').textContent,
            price: product.querySelector('.price').textContent,
            id: product.querySelector('button').getAttribute('data-id'),
            quantity: 1,
        };
        const productExist = allProducts.some(product => product.id === productInfo.id);
        if(productExist) {
            const products = allProducts.map(product => 
                product.id === productInfo.id ? {...product, quantity: product.quantity + 1} : product
            );
            allProducts = [...products];
        }
        else
        {
            allProducts = [...allProducts, productInfo];
        }
    showHTML();
    }
});

rowProducts.addEventListener('click', (e) => {
    if(e.target.classList.contains('remove')) {
        cartCount--;
        updateCartValue[0].innerText = cartCount;
        const product = e.target.parentElement.parentElement;
        const productId = product.querySelector('a').getAttribute('data-id');
        allProducts = allProducts.filter(product => product.id !== productId);
        product.remove();
    }
    showHTML();
});

const showHTML = () => 
{
    rowProducts.innerHTML = '';
    let total = 0;
    let totalQuantity = 0;

    allProducts.forEach(product => {
        const {image, title, price, quantity, id} = product;
        const row = document.createElement('tr');
        row.innerHTML = `
            <td>
                <img src="${image}" width=100>
            </td>
            <td>${title}</td>
            <td>${price}</td>
            <td>${quantity}</td>
            <td>
                <a href="" class="remove" data-id="${id}">X</a>
            </td>
        `;
        rowProducts.append(row);
        total += quantity * parseFloat(price.replace('€', ''));
        totalQuantity += quantity;
        
    });
    valorTotal.innerText = `${total}€`;
}
