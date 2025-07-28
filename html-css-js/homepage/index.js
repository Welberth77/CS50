const text = "Welberth Oliveira!";
const typingText = document.getElementById("typing-text");

let index = 0;
function typingEffect() {
  if (index < text.length) {
    typingText.textContent += text.charAt(index);
    index++;
    setTimeout(typingEffect, 150); // tempo entre letras (100ms)
  }
}

typingEffect();
