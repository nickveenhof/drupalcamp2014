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

      // $('#navbar').hover(function(){
      //   $(this).addClass('open');
      //   $('.maincontainer').addClass('open');
      // });

      $('<a href="#" class="closemenubutton open"><svg version="1.1" id="closemenubutton-closed" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="22px" height="22px" viewBox="0 0 22 22" enable-background="new 0 0 22 22" xml:space="preserve"><path fill-rule="evenodd" clip-rule="evenodd" d="M11,22c6.075,0,11-4.924,11-11c0-6.075-4.925-11-11-11S0,4.926,0,11C0,17.076,4.925,22,11,22z M8.594,7.562l1.375-1.375L14.781,11l-4.812,4.812l-1.375-1.375L12.031,11L8.594,7.562z"/></svg><svg version="1.1" id="closemenubutton-open" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="22px" height="22px" viewBox="0 0 22 22" enable-background="new 0 0 22 22" xml:space="preserve"><path fill-rule="evenodd" clip-rule="evenodd" d="M11,0C4.925,0,0,4.924,0,11c0,6.075,4.925,11,11,11s11-4.926,11-11C22,4.924,17.075,0,11,0z M13.406,14.438l-1.375,1.375L7.219,11l4.812-4.812l1.375,1.375L9.969,11L13.406,14.438z"/></svg></a>').prependTo('#intro');
      var windowwidth = $(window).width();
      if (windowwidth > 960) {
        $('#navbar').addClass('open');
        $('.maincontainer').addClass('open');
        $('.closemenubutton').removeClass('open');
      }
      $('.closemenubutton').click(function(){
        $(this).toggleClass('open');
        $('#navbar').toggleClass('open');
        $('.maincontainer').toggleClass('open');
      });

      // intro sponsors delay + fading
      $('.front #intro #block-block-3').hide().delay(2000).fadeIn(700);

      // intro CTA delay + fading
      $('#intro #block-block-4').hide().delay(3000).fadeIn(700);

      // main menu sliders submenu

      var sideMenuTopLinks = $('#navbar #block-system-main-menu > .content > ul > li.expanded');
      $('<div class="dropbutton"></div>').appendTo(sideMenuTopLinks);
      sideMenuTopLinks.each(function(){
        $(this).find('.dropbutton').click(function(){
          $(this).parent().toggleClass('open');
          $(this).parent().find('> ul').slideToggle(100);
        });
      });
      // $('<li class=""><a>Menu</a></li>').prependTo('#navbar #block-system-main-menu > .content > ul');

      // add class to content when sidebar exists
      if ($('#content-sidebar').length) {
        $('#content-content').addClass('has-sidebar');
      }

      // move searchform and accountmenu to mainmanu
      $('<li class="login-mainmenu"><a href="/user">Login</a></li>').appendTo('.not-logged-in #navbar #block-system-main-menu > .content > ul');
      $('<li class="login-mainmenu"><a href="/user/register">Register</a></li>').appendTo('.not-logged-in #navbar #block-system-main-menu > .content > ul');
      $('<li class="searchform-mainmenu"></li>').appendTo('#navbar #block-system-main-menu > .content > ul');
      $('#navbar #block-search-form #search-block-form').appendTo('.searchform-mainmenu');

      // add toplink in sidebar menu
      $('<li class="sidebartoplink"><a href="/drupalcamp">Drupalcamp</a></li>').prependTo('#content-sidebar #block-menu-block-1 ul');
      $('.page-node-3 .sidebartoplink a').addClass('active');

      // tabs empty fix
      if ($('.tabs').text() == '') {
        $('.tabs').hide();
      }


    }
  };
})(jQuery);

(function ($) {
  Drupal.behaviors.angular = {
    attach: function (context, settings) {

      


    }
  };
})(jQuery);