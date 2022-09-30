# README #

This README would normally document whatever steps are necessary to get your application up and running.

### What is this repository for? ###

Install
- Python
    Add to classpath
- http://win-builds.org/
    Install all especially 
    Add bin folder to PATH

1) Compile
pio run -e nodemcuv2

2) Write data to FS
pio run -t uploadfs

3) Run on board
pio run -t upload

4) Test
pio test -e native