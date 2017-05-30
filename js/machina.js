var w = 500;
var h = 120;
var i = 0;
var horizontal = 0;
var origin;
var paintBreak = 0;
var paintGap = 100;
var aPrev;
var hexA = "FFFFFF";

function preload() {
}

function setup(){
  var canvas = createCanvas(windowWidth,windowHeight);
  canvas.parent("rothkoCanvas");
  origin = createVector(random(10,windowWidth-10),random(10,windowHeight-10));
}

function draw(){
  noStroke();
  var colorA = color(149,156,166,80);
  var colorB = color(65,69,70,60);

  var num1 = 0;
  var num2 = 0;
  var num3 = 0;
  num1 = parseInt(hexA.substring(0,2), 16);
  num2 = parseInt(hexA.substring(2,4), 16);
  num3 = parseInt(hexA.substring(4,6), 16);

  colorA = color(num1,num2,num3,80);

  rothko();

  paintBreak++;

  if (paintBreak == paintGap){
    createPaint(1, colorA, colorB);
    paintBreak = 0;
  }

  var a1 = document.getElementById("hexA1").selectedIndex;  
  if (a1 != aPrev){
    console.log(document.getElementsByTagName("option")[a1].value);
    var charHex = hexA.replace(hexA.charAt(0), document.getElementsByTagName("option")[a1].value);
    hexA = charHex;
    aPrev = a1;
    console.log(hexA);


    fill(color(num1, num2, num3));
    rect(600,300,200,400);
  }
}

function rothko(){
  noStroke();
  rectMode(CORNERS);
  i++;
  var wr = random(-1,1);
  var hr = random(-1,1);
  fill(220,203,187,random(1,10));
 
  if (i%100 == 0){
    origin = createVector(random(10,windowWidth-10),random(10,windowHeight-10));
    i = 0;
    horizontal++;
  }
 
  if (horizontal == 5){
    fill(220,203,187,10);
    rect(origin.x, origin.y,origin.x + 300,windowHeight);
    horizontal = 0;
  }

  rect(origin.x,origin.y,origin.x - w*wr,origin.y - h*hr);
  fill(220,203,187,random(1,5));
  rect(origin.x,origin.y,origin.x - w*wr,origin.y - h*hr);
}

function createPaint(num, c1, c2){
  stroke(c1);
  var x1, y1;
  var x2, y2;
  var x3, y3;
  var x4, y4;

  var interB;
  var from = c1;
  var to = c2;
  var xoff = 0;
  num = 2;

  for (var a = 0; a < num; a++){
    x1 = random(-200,windowWidth/2+200);
    y1 = random(-200, windowHeight+200);
   
    x2 = x1 + 60;
    y2 = y1 + random(-20,30);
   
    x3 = x1 + random(900,windowWidth); //length
    y3 = y1 + random(-200,300); //direction
   
    x4 = x3 - 60;
    y4 = y3 + random(-30,20);

    var rand = random(180,300);
   
    for(var i = 0; i <= rand; i++) {
       xoff = xoff + 1;
       var n = noise(xoff);   
       noFill();
       strokeWeight(1);
       var interB = lerpColor(from, to, n);  
       bezier(x1, y1+i, x2, y2+i, x3, y3+i, x4, y4+i);
       stroke(interB, 150);  
    }
   }
}

function keyPressed() {
  if (keyCode == BACKSPACE) {   
  }
}