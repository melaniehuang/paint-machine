var w = 500;
var h = 120;
var i = 0;
var horizontal = 0;
var origin;
var paintBreak = 0;
var paintGap = 50;
var aPrev;

var selectBoxes = {
  82: "hexA0", // R
  84: "hexA1", // T
  89: "hexA2", // Y
  85: "hexA3", // U
  73: "hexA4", // I
  79: "hexA5", // D
  80: "hexB0", // P
  71: "hexB1", // G 
  72: "hexB2", // H
  74: "hexB3", // J
  75: "hexB4", // K
  76: "hexB5", // L
};

var selectChannels = {};

var selectValues = {
  48: ["0", "8"], // 0
  49: ["1", "9"], // 1
  50: ["2", "A"], // 2
  51: ["3", "B"], // 3
  52: ["4", "C"], // 4
  53: ["5", "D"], // 5
  54: ["6", "E"], // 6
  55: ["7", "F"], // 7
};

var selectNum = selectBoxes[82];

function preload() {
  for (sb in selectBoxes) {
    selectChannels[selectBoxes[sb]] = 0;
  }
}

function setup(){
  var canvas = createCanvas(windowWidth,windowHeight);
  canvas.parent("rothkoCanvas");
  origin = createVector(random(10,windowWidth-10),random(10,windowHeight-10));
  background(144,133,125);
  clearPainting();
}

function draw(){
  noStroke();
  var colorA = mixPaint(getPaint("A")); 
  var colorB = mixPaint(getPaint("B"));  

  rothko();
  paintBreak++;

  if (paintBreak == paintGap){
    createPaint(1, colorA, colorB, 200,200);
    paintBreak = 0;
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

function getPaint(s){
  var h = "";
  for (var i = 0; i < 6; i++){
    var selectValue = $("#hex" + s + i + " :selected").text(); // The text content of the selected option    
    h += selectValue;
  }
  return h;
}

function mixPaint(h){
  var hexColor = h;
  var colorRGB = [
    parseInt(hexColor.substring(0,2), 16),
    parseInt(hexColor.substring(2,4), 16),
    parseInt(hexColor.substring(4,6), 16)
  ];
  return color(colorRGB[0],colorRGB[1],colorRGB[2],80);
}

function createPaint(num, c1, c2, paintWidth, paintLength){
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

    var rand = random(paintWidth,paintWidth*2);
   
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

function clearPainting() {
  setInterval(function(){
    saveCanvas(canvas, "lastmachine", "jpg");
    clear();
  }, 120000); //60000 = 1 min
}

document.addEventListener('keydown', function(event) {
  if (event.keyCode in selectBoxes) {
    selectNum = selectBoxes[event.keyCode];
    console.log(selectNum);
  }


  if (event.keyCode in selectValues) {
    let hexDigit = selectValues[event.keyCode];
    let newvalue = document.getElementById(selectNum);
    let channel = selectChannels[selectNum];

    newvalue.value = hexDigit[channel];

    if (event.keyCode == 55) {
      selectChannels[selectNum] = (channel + 1) % 2;
    }
  }
}, true);