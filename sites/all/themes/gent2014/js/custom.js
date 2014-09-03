(function ($) {
  Drupal.behaviors.theming = {
    attach: function (context, settings) {

      // flex slideshow homepage
      $('#bg').flexslider({
        selector: "ul > li.slide",
        animation: 'fade',
        pauseOnHover: false,
        slideshowSpeed: 12000,
        animationSpeed: 3000,
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
      $('.front #intro').height(windowHeight-70);
      // $('.front #intro-inner').css('padding-top',(((windowHeight-70)-introInnerHeight)/2));
      // on resize
      $(window).resize(function(){
        var windowHeight = $(window).height();
        var introInnerHeight = $('#intro-inner').height();
        $('.front #intro').height(windowHeight-70);
        // $('.front #intro-inner').css('padding-top',(((windowHeight-70)-introInnerHeight)/2));
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
          $(this).next().slideToggle(100);
          $(this).toggleClass('open');
        });
      };

      $('#block-user-login').sliderElement();
      // $('#block-system-main-menu').sliderElement();
      $('#block-system-user-menu').sliderElement();
      $('#block-search-form').sliderElement();

      // menu horizontal slider
      $.fn.menuSliderElement = function() {
        $('<div class="sliderbutton '+this.attr('id')+'"></div>').insertBefore(this);
        this.prev().click(function(event){
          $(this).next().toggleClass('open');
          event.stopPropagation();
        });
        $('#content,#intro,#footer').click(function(){
          $('#block-system-main-menu').removeClass('open');
        });
      };

      $('#block-system-main-menu').menuSliderElement();

      // intro sponsors delay + fading
      $('#intro #block-block-3').hide().delay( 2000 ).fadeIn( 1000 );

      // main menu sliders submenu
      var sideMenuTopLinks = $('#menubar #block-system-main-menu > .content > ul > li');
      sideMenuTopLinks.each(function(){
        $(this).click(function(){
          $(this).toggleClass('open');
          $(this).find('> ul').slideToggle(100);
        });
      });


    }
  };
})(jQuery);