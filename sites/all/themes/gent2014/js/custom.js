(function ($) {
  Drupal.behaviors.theming = {
    attach: function (context, settings) {

      // flex slideshow homepage
      $('#bg').flexslider({
        selector: "ul > li.slide",
        animation: 'fade',
        pauseOnHover: false,
        slideshowSpeed: 12000,
        animationSpeed: 1500,
        minItems: 1,
        maxItems: 1,
        move: 1,
        animationLoop: true,
        randomize: true,
        controlNav: false,
        directionNav: false
      });

      // intro window height
      // init
      var windowHeight = $(window).height();
      var introInnerHeight = $('#intro-inner').height();
      $('.front #intro').height(windowHeight);
      // on resize
      $(window).resize(function(){
        var windowHeight = $(window).height();
        var introInnerHeight = $('#intro-inner').height();
        $('.front #intro').height(windowHeight);
      });

      // menubar sticky
      // init
      var stickyNavTop = $('#menubar').offset().top;
      var stickyNav = function(){
        var scrollTop = $(window).scrollTop();
        if (scrollTop >= stickyNavTop) {
            $('#menubar, #content').addClass('sticky');
        } else {
            $('#menubar, #content').removeClass('sticky');
        }
      };
      stickyNav();
      $(window).scroll(function() {
          stickyNav();
      });
      // on resize
      $(window).resize(function(){
        var stickyNavTop = $('#menubar').offset().top;
        var stickyNav = function(){
          var scrollTop = $(window).scrollTop();
          if (scrollTop >= stickyNavTop) {
              $('#menubar, #content').addClass('sticky');
          } else {
              $('#menubar, #content').removeClass('sticky');
          }
        };
        stickyNav();
        $(window).scroll(function() {
            stickyNav();
        });
      });

      // slider elements
      $.fn.sliderElement = function() {
        $('<div class="sliderbutton '+this.attr('id')+'"></div>').insertBefore(this);
        this.hide();
        this.prev().click(function(){
          $(this).next().fadeToggle(100);
          $(this).toggleClass('open');
        });
      };

      $('#block-user-login').sliderElement();
      $('#block-system-user-menu').sliderElement();
      $('#block-search-form').sliderElement();

      $('#navbar').hover(function(){
        $(this).toggleClass('open');
        $('.maincontainer').toggleClass('open');
      });

      // intro sponsors delay + fading
      $('#intro #block-block-3').hide().delay(2000).fadeIn(700);

      // intro CTA delay + fading
      $('#intro #block-block-4').hide().delay(3000).fadeIn(700);

      // main menu sliders submenu
      var sideMenuTopLinks = $('#navbar #block-system-main-menu > .content > ul > li');
      sideMenuTopLinks.each(function(){
        $(this).click(function(){
          $(this).toggleClass('open');
          $(this).find('> ul').slideToggle(100);
        });
      });
      $('<li class=""><a>Menu</a></li>').prependTo('#navbar #block-system-main-menu > .content > ul');

      // add class to content when sidebar exists
      if ($('#content-sidebar').length) {
        $('#content-content').addClass('has-sidebar');
      }

      // move searchform and accountmenu to mainmanu
      $('<li class="login-mainmenu"><a href="/user">Login</a></li>').appendTo('.not-logged-in #navbar #block-system-main-menu > .content > ul');
      $('<li class="login-mainmenu"><a href="/user/register">Register</a></li>').appendTo('.not-logged-in #navbar #block-system-main-menu > .content > ul');
      $('<li class="searchform-mainmenu"></li>').appendTo('#navbar #block-system-main-menu > .content > ul');
      $('#navbar #block-search-form #search-block-form').appendTo('.searchform-mainmenu');



    }
  };
})(jQuery);

(function ($) {
  Drupal.behaviors.angular = {
    attach: function (context, settings) {

      


    }
  };
})(jQuery);