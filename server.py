# https://gist.github.com/scottj/a510d6bd96941901fb99554566ee226d

import http.server
import socketserver

HOST = "localhost"
HOST = "192.168.1.229"
HOST = "0.0.0.0"
PORT = 8000


class HttpRequestHandler(http.server.SimpleHTTPRequestHandler):
    def __init__(self, *args, **kwargs): # https://stackoverflow.com/questions/39801718/how-to-run-a-http-server-which-serves-a-specific-path
        super().__init__(*args, directory="docs", **kwargs)
    extensions_map = {
        "": "application/octet-stream",
        ".css": "text/css",
        ".html": "text/html",
        ".jpg": "image/jpg",
        ".js": "application/x-javascript",
        ".json": "application/json",
        ".manifest": "text/cache-manifest",
        ".pdf": "application/pdf",
        ".png": "image/png",
        ".svg": "image/svg+xml",
        ".wasm": "application/wasm",
        ".xml": "application/xml",
    }


try:
    with socketserver.TCPServer((HOST, PORT), HttpRequestHandler) as httpd:
        print(f"serving at http://{HOST}:{PORT}")
        httpd.serve_forever()
except KeyboardInterrupt:
    pass
