const express=require("express");
const session = require('express-session')
const app=express();
const fs=require("fs");
const formidable= require("formidable");
const port = 3000;
app.use(express.static("Json"));
//app.use(express.static("poze"));
app.use(express.static("site"));
app.set("view engine","ejs");
app.use('/intrebare', express.urlencoded({extended:true}));
app.get('/', (req, res) => {
    res.sendFile('/index.html');
});
//res.sendfile('./main.html');


//var vector = '{"cod1": "ab71234", "cod2":}'

/*app.get("/rasintrebari", function(req,res){
  var form= new formidable.IncomingForm();
  var vector =fs.readFileSync('site/quiz.json');
  var el = JSON.parse(vector);
  form.parse(req,function(err,fields,files){
      var intrebare=fields.question;
      var ras=fields.answer;
      var dif = fields.difficulty;
      res.send(ras);
  })
});*/
//login si logout

app.use(session({
  secret: 'Nu spune nimanui parola!',
  name: 'uniqueSessionID',
  saveUninitialized: false
}))

app.get('/logout', (req, res) => {
  req.session.destroy((err) => {})
  res.writeHead(301, { Location: 'http://localhost:3000/' + 'index.html' });
  res.end();

});

app.post("/adaugauser", function(req, res) {

  var form = new formidable.IncomingForm();
  var date;
  if (fs.existsSync("site/useri.json")) {
      var utilizatori = fs.readFileSync("site/useri.json", "utf8");
      date = JSON.parse(utilizatori);
  } else
      date = [];
  form.parse(req, function(err, fields) {
      var user = fields.user;
      var pass = fields.pass;
      ob = { user: user, pass: pass };
      date.push(ob);
      fs.writeFileSync("site/useri.json", JSON.stringify(date));
      res.send("Utilizatorul " + user + " a fost adaugat cu parola " + pass + ' <a href="formular.html ">La login</a>');
  })
})

app.post("/login", function(req, res) {

  var form = new formidable.IncomingForm();
  var date = [];
  form.parse(req, function(err, fields) {
      var user = fields.user;
      var pass = fields.pass;
      ob = { user: user, pass: pass };
      date.push(ob);
      
      var veri = 0;
      var login = fs.readFileSync("site/useri.json", "utf8");
      var datelogin = JSON.parse(login);

      for (let i = 0; i < datelogin.length; i++)
          if (datelogin[i].user == ob.user && datelogin[i].pass == ob.pass) {
              veri = 1;
              req.session.loggedIn = true;
              req.session.username = datelogin[i].user;
              res.writeHead(301, { Location: 'http://localhost:3000/' + 'index.html' });
              res.end();
          }
      if (veri == 0) {
          req.session.username = false;
          res.send('Date gresite! <a href="acreditari_login.html ">Inapoi la login</a>');
      }
  })
});




app.post("/salveaza", function(req, res) {
  var form = new formidable.IncomingForm();
  
  form.keepExtensions = true;
  var date;
  if (fs.existsSync("site/quiz1.json")) {
      var intr = fs.readFileSync("site/quiz1.json", "utf8");
      date = JSON.parse(intr);
  } else
      date = [];
  form.parse(req, function(err, fields, files) {
      var intrebari = fields.question;
      var rasp = fields.answer;
      var dif = fields.difficulty;

      ob = { question: intrebari, answer: rasp, difficulty: dif };
      date.push(ob);
      fs.writeFileSync("site/quiz1.json", JSON.stringify(date));
      res.send("S-a adaugat intrebarea " + intrebari + " cu raspunsul " + rasp + " si cu dificultatea " + dif);
  })
})

app.get("/intr", function(req, res) {
  var intr = fs.readFileSync("site/quiz1.json", "utf8");
  var date = JSON.parse(intr);
  res.render("Intrebari", { intr: date });
})



app.post("/intrebare", function(req,res){
    var cuv=req.body.cuvant;
    var limba=req.body.limba;
    var raspuns="";
    //const dictionar = JSON.parse(txt);
    const dictionar = [{cuvant:"Cati ani are Arthur?", RDR2:"El are 36 de ani!", RDR1:"El ar fi avut 47 de ani!"}, {cuvant:"Cand a aparut jocul?", RDR2:"Jocul a aparut pe 26 octombrie 2018!", RDR1:"Jocul a aparut pe 18 mai 2010!"},{cuvant:"Cate arme se gasesc in joc?", RDR2:"Se gasesc 50 de arme!", RDR1:"Se gasesc 28 de arme"}, {cuvant:"Cate tipuri de cai diferiti sunt in joc?", RDR2:"Sunt 19 tipuri!", RDR1:"Sunt 30 de tipuri!"}];
    for (x of dictionar){
      if (x.cuvant==cuv){
        if (limba=="RDR2")
        raspuns= x.RDR2;
        else
        raspuns=x.RDR1;
      }
    }
    if(raspuns)
      res.send(raspuns);
    else
      res.send("Intrebarea nu exista");
  });


  app.get("/codsecret", function(req,res){
    res.send("ab71234");
  });
 

app.listen(port, () => {
    console.log(`http://localhost:${port}`)
})
app.use(function(req, res, next) {
  res.status(404).send("404 Not Found")
});
app.listen(8000,function(){console.log("Serverul a pornit");});
