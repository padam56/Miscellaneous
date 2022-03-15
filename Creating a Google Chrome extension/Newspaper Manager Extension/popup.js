document.addEventListener('DOMContentLoaded', function() {
    var port = chrome.runtime.connect();
    document.getElementById('print').addEventListener('click', function() {
        port.postMessage({from: 'popup'});
    });
});