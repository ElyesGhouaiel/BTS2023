function agrandissement() {
  var myImg = document.getElementById("myImg");
  var width = myImg.clientWidth;
  var height = myImg.clientHeight;
  if (width == 420) {
      alert("Le ballon a explosé");
      myImg.style.width = `${200}px`;
  }    else if (height == 420 ){
      alert("Le ballon a explosé");
      myImg.style.height = `${200}px`;
  }   else {
      myImg.style.width = ( width + 10 ) + "px";
      myImg.style.height = ( height + 10 ) + "px";
  }
}

var btn = document.getElementById('btn');
btn.addEventListener('click', function onClick(event) {
const backgroundColor = btn.style.backgroundColor;

if (backgroundColor === 'red') {
  btn.style.backgroundColor = 'green';
} else if (backgroundColor === 'green') {
  btn.style.backgroundColor = 'blue';
} else {
  btn.style.backgroundColor = 'red';
}
})

function retrecissement() {
  var myImg = document.getElementById("myImg");
  var width = myImg.clientWidth;
  var height = myImg.clientHeight;
  if (width>=200,height>=200){
    myImg.style.height = ( height - 5 ) + "px";
    myImg.style.width = ( width - 5 ) + "px";
  }
}

var btn = document.getElementById('btn');
btn.addEventListener('mouseleave', transformation)
function transformation(event){
  const backgroundColor = btn.style.backgroundColor;
  
  if (backgroundColor === 'blue') {
    btn.style.backgroundColor = 'green';
  } else if (backgroundColor === 'green') {
    btn.style.backgroundColor = 'red';
  } else {
    btn.style.backgroundColor = 'blue';
  } 
  retrecissement();
  }

