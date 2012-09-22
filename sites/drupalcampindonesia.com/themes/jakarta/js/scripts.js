(function() {
  var html = document.getElementsByTagName('html')[0],
      left = 0;
  setInterval(function() {
    html.style.backgroundPosition = --left + 'px 0';
  }, 50);
})();
