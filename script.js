var speechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition;
var recognition = new speechRecognition()
var textbox = $("#textarea")
var ins = $("#recording-instructions")
var content = ''

recognition.continuous = true;
recognition.lang = "ar";
recognition.onstart = function(){
    ins.text("تحدث")
}
recognition.onspeechend = function(){
    ins.text("أضغط تشغيل للتعرف على الصوت")
}
recognition.onerror = function(){
    ins.text("لقد حدث خطأ, حاول مرة اخرى")
}
recognition.onresult = function(event){
    var current = event.resultIndex;
    var transcript = event.results[current][0].transcript

    content += transcript
    onChangespeech()
    textbox.val(content)
}

$("#start-record-btn").click(function(){
    recognition.start()
})
$("#pause-record-btn").click(function(){
    recognition.stop()
    ins.text("أضغط تشغيل للتعرف على الصوت")
})
$("#clear-btn").click(function(){
    textbox.val("")
    content = ""
})