chrome.runtime.onConnect.addListener(function(port) {
    port.onMessage.addListener(function(o) {
        if (o.from && o.from === 'popup') {
            chrome.tabs.executeScript(null, {
                code: "window.print();"
            });
        }
    });
});