var timerID;
function sayHi() {
    alert('Prea incet!!');
    timerID= setTimeout(sayHi,10000)
  }
  setTimeout(sayHi,1000000)

//Formular Validare
  var input = document.getElementById("input");
  var buton = document.getElementById("validare");
  var test ;
  buton.onclick = function validate() {
    var cod = input.value;
    var Truecode = /^[a-z]{2}[-\s\.]{0}[7]{1}[-\s\.]{0}[0-9]{4}$/;
    test = Truecode.test(cod);
    if (test == false)
        document.getElementById("valid").innerHTML = 'Codul nu exista!';
    else document.getElementById("valid").innerHTML = 'Cod corect!';

}


  var i ;
  var img = document.getElementById("imagine");
  img.onclick = function() {

    if (img.className == 'po1') {
        i = document.querySelector('.po1');
        i.classList.remove('po1');
        i.classList.add('po2');
    } else {
        i = document.querySelector('.po2');
        i.classList.remove('po2');
        i.classList.add('po1');
    }
}
let para = document.getElementById("imagine");
let compStyles = window.getComputedStyle(para);
para.textContent='Padingul este'+compStyles.getPropertyValue('padding');

window.onload=function(){
    fetch("quiz.json").then(function(res){
      res.text().then(function(text){
        var intrebari=JSON.parse(text);
        afisare(intrebari);
       
      })
    })
}

function afisare(intrebari){
  var buton1=document.getElementById("b1");
  var nr;
  buton1.onclick=function(){
    nr= Math.floor(Math.random()*intrebari.test.length);
    document.getElementById("intrebare").innerHTML=intrebari.test[nr].question;
    document.getElementById("dif").innerHTML=intrebari.test[nr].difficulty;
    document.getElementById("raspuns").innerHTML="";
  }
  document.getElementById("b2").onclick=function(){
    document.getElementById("raspuns").innerHTML=intrebari.test[nr].answer;
  }

}

// Check browser support

//