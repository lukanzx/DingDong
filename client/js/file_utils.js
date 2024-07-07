.pragma library

function readFile(url, onLoad, onProgress, onError) {
    var request = new XMLHttpRequest();

    request.onreadystatechange = function() {
        if (request.readyState === XMLHttpRequest.DONE) {
            if (request.status === 200 || request.status === 0) {
                console.time('Process file: "' + url + '"');
                onLoad( request.responseText );
                console.log("responseText: " + request.responseText);
                console.timeEnd('Process file: "' + url + '"');
            }
             else if ( onError !== undefined ) {
               onError();
            }
        }
       else if (request.readyState === XMLHttpRequest.HEADERS_RECEIVED) {
           if ( onProgress !== undefined ) {
               onProgress();
            }
       }
    };

    request.open( 'GET', url, true );
    request.send( null );
}

function saveFile(url, text, onLoad, onProgress, onError) {
    var request = new XMLHttpRequest();

    request.onreadystatechange = function() {
        if (request.readyState === XMLHttpRequest.DONE) {
            if (request.status === 200 || request.status === 0) {
                console.time('Process file: "' + url + '"');
                onLoad( request.responseText );
                console.log("responseText: " + request.responseText);
                console.timeEnd('Process file: "' + url + '"');
            }
             else if ( onError !== undefined ) {
               onError();
            }
        }
       else if (request.readyState === XMLHttpRequest.HEADERS_RECEIVED) {
           if ( onProgress !== undefined ) {
               onProgress();
            }
       }
    };

    request.open( 'PUT', url, true );
    request.send( text );
}
