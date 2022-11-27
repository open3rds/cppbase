# cppbase@open3rds

This is a repository for demonstration of c++ development.


# Usage of base repo 
[remove this section in new projects]
```shell
git clone https://github.com/open3rds/cppbase.git
mv cppbase ${YourProjectName}
cd ${YourProjectName}
rm -rf .git
git init
git add .
git commit -m "Init project template"
```

# Usage

How to reference this library, see: https://github.com/open3rds or [example/](example/).

## Add

```cpp
template<typename ...Args>
auto add(Args&&... args) noexcept;
```

Add variable length of arguments together, use plus sign internal.
```cpp
auto result = open3rds::add(1, 2, 1.125);
```

# Project Structure

## example/

A simple example of use this repo as a internal referenced library.

It should be able to be built when its entirely copied out from the root direcotry, a.k.a. independantly.

## include/

Header files, name of cpp srcs ends with `.hpp` while c srcs ends with `.h`.

## src/

Source files, name of files ends with either `.cpp` or `.c` (sometime with `.py` etc.).

## test/

Unittests, use gtest by default.