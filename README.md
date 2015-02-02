# BBQ: Better than raw!

## What is this?
An archive format. Totally cool, with nice features and functionalities you aren't used to. Oh, and its small. libBBQ is a tiny library that only consists of so few files, but is able to handle many features and serve many purposes. Why am I making it? Well...
- libarchive is too large.
- libcanister lacks compression.
- zlib is confusing.
- lib7zip is Windows only.
- ... There is a myriad more.

BBQ is ment for general purpose use and is able to do cool things. And, you can append it to a binary, too! This way, you can save assets to your binary.

    unix$ cat my.bbq >> mybin

## Features
- Headers, headers, headers! No, not the ones you know. In fact, you can decide WHAT headers!
    * Add custom headers to any individual archive. Like author, version, or even base64 encoded data...up to you.
    * Read the data via the library or from a script via a command line tool.
- Streaming.
    * While the JSON is copied into memory, all the data is read as it goes on.
- Stick it at the end of something else.
    * The JSON is put at the bottom, and the file is hence read from the bottom instead than the top.
    * The data itself is resolved backwards too. The total archive size is added to the JSON so all files can be resolved - no matter where the archive is!

## Example
The following is the JSON that is to be added to the archive.

```json
{
    "headers": {
        "author": "My name",
        "some": "more"
    },
    "size": 1048576,
    "files": {
        "/foo.txt": { "start": 0, "end": 1024 },
        "/folder/bar.txt": { "start": 1025, "end": "..." }
    }
}
```

## Development
This currently is only a PoC and will be worked into a proper program soon.
