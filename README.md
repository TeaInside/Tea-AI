# Tea AI
> An Artificial Intelligence.

![][code-size]
![][repo-size]
![][GitHub-issues]
![][GitHub-forks]
![][GitHub-stars]
![][GitHub-license]

This is a simple AI project that written in PHP and C++.

![](header.png)

## Installation for Ubuntu 16.xx / 18.xx

```sh
sudo apt-add-repository ppa:ondrej/php -y && sudo apt update -y && sudo apt install libphp7.2-embed php7.2 php7.2-bcmath php7.2-bz2 php7.2-cli php7.2-common php7.2-curl php7.2-dev php7.2-enchant php7.2-fpm php7.2-gd php7.2-gmp php7.2-json php7.2-ldap php7.2-mbstring php7.2-opcache php7.2-phpdbg php7.2-pspell php7.2-readline php7.2-recode php7.2-sybase php7.2-tidy php7.2-xml php7.2-xmlrpc php7.2-zip -y

sudo wget https://getcomposer.org/composer.phar -O /usr/bin/composer && sudo chmod +x /usr/bin/composer

sudo apt-get install libcurl-dev libcurl4-gnutls-dev -y

wget https://api.github.com/repos/CopernicaMarketingSoftware/PHP-CPP/tarball/v2.1.2 -O phpcpp

tar -xf phpcpp

cd *PHP*

make -j 2

sudo make install

git clone https://github.com/TeaInside/Tea-AI && cd Tea-AI

composer install -vvv

make -j 2

php -d "extension=$(pwd)/teaai.so" main.php
```

<!-- Markdown link & img dfn's -->
[code-size]: https://img.shields.io/github/languages/code-size/badges/shields.svg
[repo-size]: https://img.shields.io/github/repo-size/badges/shields.svg
[GitHub-issues]: https://img.shields.io/github/issues/TeaInside/Tea-AI.svg
[GitHub-forks]: https://img.shields.io/github/forks/TeaInside/Tea-AI.svg
[GitHub-stars]:	https://img.shields.io/github/stars/TeaInside/Tea-AI.svg
[GitHub-license]: https://img.shields.io/github/license/TeaInside/Tea-AI.svg
