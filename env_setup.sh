sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt install -y g++-11
g++-11 --version

bash <(curl -fsSL https://xmake.io/shget.text)
xmake f --toolchain=gcc-11 -c