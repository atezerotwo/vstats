var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var bodyParser = require('body-parser');

var jsonParser = bodyParser.json();

app.get('/', function(req, res){
  res.sendFile(__dirname + '/index.html');
});

app.get('/smoothie.js', function(req, res){
  res.sendFile(__dirname + '/smoothie.js');
});


io.on('connection', function(socket){
socket.on('chat message', function(msg){io.emit('chat message', msg);});
});

app.post('/feed', jsonParser, function(req1, res){
  if (!req1.body) return res.sendStatus(400)
    res.send('ok');
//    console.log(req1.body);
    io.emit('1secavg', req1.body);
});

app.post('/feed30', jsonParser, function(req30, res){
  if (!req30.body) return res.sendStatus(400)
    res.send('ok');
//    console.log(req30.body);
    io.emit('30secavg', req30.body);
});

app.post('/feed300', jsonParser, function(req300, res){
  if (!req300.body) return res.sendStatus(400)
    res.send('ok');
//    console.log(req300.body);
    io.emit('300secavg', req300.body);
});



http.listen(3000, function(){
  console.log('listening on *:3000');
});
