# GSL sample usages

# Prerequisities
GTest required default include path.

# Build:
```
   git clone https://github.com/mjgrzybek/gsl_intro.git
   git submodule init     # gsl-lite
   git submodule update
   
   mkdir build
   cd build
   cmake ..
   make
```

# Run
```
   ./gsl_intro --gtest_death_test_style=threadsafe
```