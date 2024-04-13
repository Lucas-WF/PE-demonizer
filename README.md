# PE-demonizer
Why this project exists? Even Idk

The PE-demonizer is a CLI-based tool that retrieve the "main" headers from a PE file, and overwrite them with the "DEMONIZE" word in hexa

### Installing

It's easy to install, just:

```
git clone https://github.com/Lucas-WF/PE-demonizer
cd PE-demonizer
gcc main.c -o pe-demonizer
```

### Using PE-demonizer

PE-demonizer has three main functions, to parse the headers, to overwrite the DOS-header and to overwrite the COFF-header, you can see more running the command with the ```-h``` flag.
