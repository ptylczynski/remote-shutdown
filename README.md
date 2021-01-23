# remote-shutdown

C made server for remotely closing system

## Make from source

Project is build using CMake 3.17 so it is the best way to compile your version

## Comuncation protocol

Client-Server communcation is made on `SimpleMessage` (aka SM). One SM can take up to 20 key-value pairs. There are no specified KV pairs to server works, 
but some of them are needed for e.g. to authorize request.  

Communication is as simple as sending properly formated text string

```
{
key1:value1
key2:value2
...
}
```

By default headed contains left curly bracket and new line character `\n`. Foother on other hand contains new line character `\n` and right curly bracket.
Each KV pair must end with new line. Spaces are alowded in either key or value. Other formats of message can be set by changing `MESSAGE_*` values in `utils/simple-message.h`

## Available Requests

- **suspend**  
  
```
{
action:SUSPEND
secret:sdlijkfgd
}
```

- **stop**  
  
```
{
action:STOP
secret:sdgdfsjgsldj
}
```

other KV pairs could be added but will be ignored by server. Be aware of white spaces as server don't remove them and case sensitivity
so ` abc` is  not this same as `abc` nor `Abc`

## Simple Testing

```bash
$ cat << EOF > test-req
{
action:STOP
secret:super_secret
}
EOF

$ cat test-req | nc localhost 7021
```

## Further reading

Entire code is meaningfully described and documented for some in deep lurking. `test/` dir contains some more request. Some of them are valid and other not. Invalid reqs are marked as so.

## Known extensions and clients

- Simple Android Implementation

## Project structure

- **server.h** - contains all server side logic
  
- **utils/simple-message.h** - helper functions for SM manimpulations
  
- **utils/stringops.h** - string operators
  