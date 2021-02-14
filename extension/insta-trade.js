const whisperButtonCssClass = ".whisper-btn";
const itemsContainerCssClass = ".resultset";
const rowCssClass = ".row";

function SendWhisperRequest(message) {
  console.log("Sending whisper request with:", message);
  fetch("http://localhost:8080/whisper", { mode: "no-cors", body: message })
    .then((x) => {})
    .then((x) => {});
}

function FindWhisperNode(rowNode) {
  return rowNode.querySelector(whisperButtonCssClass);
}

function HijackWhisperNode(whisperNode) {
  whisperNode.onclick = null;
  whisperNode.addEventListener("click", () => {
    SendWhisperRequest("Hello");
    whisperNode.innerText = "Hacked";
  });
}

function ElementsAdded(mutationsList, observer) {
  for (const mutation of mutationsList) {
    if (mutation.type === "childList") {
      //console.log(mutation);
      for (const addedNode of mutation.addedNodes) {
        if (addedNode.className === "row") {
          const rowNode = FindWhisperNode(addedNode);
          HijackWhisperNode(rowNode);
        }
      }
    }
  }
}

setTimeout(() => {
  const whisperNodes = document.querySelectorAll(whisperButtonCssClass);
  for (const node of whisperNodes) {
    HijackWhisperNode(node);
  }

  const targetNode = document.querySelector(itemsContainerCssClass);
  if (targetNode) {
    const config = { childList: true, subtree: true };
    const observer = new MutationObserver(ElementsAdded);
    console.log(targetNode);
    observer.observe(targetNode, config);

    //observer.disconnect();
  } else {
    console.log("Can't find items container", targetNode);
  }
}, 3000);
