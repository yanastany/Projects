
var Vimg=['Abigail.jpg','Arthur.jpg','Dutch.jpg','Hosea.jpg','Jack.jpg','Javier.jpg','John.jpg','Karen.jpg','Sadie.jpg','Sean.jpg','Susan.jpg']
var Vnume= new Array();
var input = document.getElementById("guess");
Vnume[0] = "abigail";
Vnume[1] = "arthur";
Vnume[2] = "dutch";
Vnume[3] = "hosea";
Vnume[4] = "jack";
Vnume[5] = "javier";
Vnume[6] = "john";
Vnume[7] = "karen";
Vnume[8] = "sadie";
Vnume[9] = "sean";
Vnume[10] = "susan";
var scor = document.querySelector(".score");
var hscor = document.querySelector(".highscore");
var buton2 = document.getElementById("again");
var h = 0;var vieti=3;
var num;
var nume;
var mesaj;
var buton1=document.getElementById("check");
buton2.onclick = function(){
    document.getElementById("jucatori").style.color="white";
    buton1.disabled=false;
    nume = prompt("Introduceti numele:");
    mesaj = document.querySelector(".message");
    mesaj.innerHTML = "";
    mesaj.innerHTML += " " + nume;
    
    num = Math.floor(Math.random() * Vimg.length);
    var img = Vimg[num];
   
    var imgStr = '<img src="' + img + '" alt = "" style="height: auto; width: 400px;">';
    document.getElementById("imagine").innerHTML = imgStr;
    vieti = 3;
    document.getElementById("vieti").innerHTML = '<span id="vieti">Vieti:' + vieti + '</span>';
}


buton1.onclick = function(){
    document.getElementById("vieti").innerHTML = '<span id="vieti">Vieti:' + vieti + '</span>';
  if(vieti>0)
  {
      var raspuns=input.value;
        var r = raspuns.toLowerCase();
      if(r==Vnume[num]){
        document.getElementById("jucatori").style.color="green";
        mesaj.innerHTML = "Ati ghicit numele ";
        //scor.innerHTML = vieti;
       // if(h<vieti){
          //  h=vieti;
        //}
        //hscor.innerHTML = h;
        var paragraf=document.createElement("p");
        paragraf.innerHTML=nume+ " a castigat jocul cu scorul " + vieti;
        document.getElementById("jucatori").appendChild(paragraf);
        paragraf.className="jucator";

      }
      else
      {
          vieti= vieti-1;
          document.getElementById("vieti").innerHTML = '<span id="vieti">Vieti:' + vieti + '</span>';
          mesaj.innerHTML = "Raspuns gresit!";
      }
  }
  if(vieti==0){
    
    document.getElementById("vieti").innerHTML = '<span id="vieti">Vieti:' + vieti + '</span>';
    mesaj.innerHTML = "Joc Pierdut!";
    var paragraf=document.createElement("p");
    paragraf.innerHTML=nume+ " a pierdut! ";
    document.getElementById("jucatori").appendChild(paragraf);
   // paragraf.className="jucator";
    buton1.disabled=true;
  }  
}

window.onload=function(){

  if(!localStorage.getItem("mesaj"))
  {
    localStorage.setItem("mesaj","JOC");
  }
  else{
    var string=localStorage.getItem("mesaj");
    localStorage.setItem("mesaj", string + "!");
    document.getElementById("titlu").innerHTML=localStorage.getItem("mesaj")+"!";  
  
  }
  document.getElementById("titlu").onclick=function(){
    //localStorage.clear();
    localStorage.removeItem("mesaj");
    location.reload();
  }
  
  }
 


