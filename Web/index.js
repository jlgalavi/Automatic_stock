const navToggle = document.querySelector('.nav-toggle');
const navMenu = document.querySelector('.nav-menu');

navToggle.addEventListener('click', () => 
{
    navMenu.classList.toggle('nav-menu_visible')
    if(navMenu.classList.contains('nav-menu_visible'))
    {
        navToggle.setAttribute('aria-label', 'Close menu');
    }
    else
    {
        navToggle.setAttribute('aria-label', 'Open menu');
    }
});

const menuLinks = document.querySelectorAll('.nav-menu a[href^="#"]');
menuLinks.forEach(menuLink => 
    {
    menuLink.addEventListener('click', () => {
        navMenu.classList.remove('nav-menu_visible');
        navToggle.setAttribute('aria-label', 'Close menu');
    });
});