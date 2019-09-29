# IngressoNet

IngressoNet é um modelo de sistema de venda de ingressos. O projeto está em desenvolvimento para a matéria Técnicas de Programação 1 do CIC/UnB. O sistema deve funcionar com uma arquitetura em camadas para vender ingressos para partidas locais, regionais, estaduais, nacionais e internacionais. OS usuários podem criar e administrar até 5 partidas simultaneamente e podem se descadastrar quando necessário, exceto enquanto administram alguma partida.

## Primeiros Passos

O sistema foi desenvolvido utilizando o framework Qt e depende de uma instalação do docker e docker-compose para execução. Veja as notas de deploy para instruções de como fazer o deploy do sistema para produção.

### Pré requisitos

#### Qt

O código foi desenvolvido utilizando o framework Qt 5, para instalá-lo no linux, acesse o [site oficial](https://www.qt.io/download#section-2) ou siga os passos abaixo(disponíveis em [Install Qt 5 on Ubuntu](https://wiki.qt.io/Install_Qt_5_on_Ubuntu)) para instalar pelo terminal. É recomendada a instalação do Qt creator por meio do download do site oficial.

Baixe o instalador
```bash
wget http://download.qt.io/official_releases/qt/5.7/5.7.0/qt-opensource-linux-x64-5.7.0.run
```

Forneça permissão para execução, execute o instalador e siga os passos para concluir a instalação
```bash
chmod +x qt-opensource-linux-x64-5.7.0.run
./qt-opensource-linux-x64-5.7.0.run
```

Instale o compilador g++
```bash
sudo apt-get update
sudo apt-get install build-essential
```

Caso você utilize alguma distribuição de arch, o comando para instalação do g++ será o seguinte.
```bash
sudo pacman -Sy base-devel
```

Isto deve ser o suficiente para iniciar o QtCreator. Caso seja necessário, configure o compilador, instale as bibliotecas de OpenGL e associe arquivos .pro ao QtCreator. Para mais informações, acesse a [documentação do Qt](https://wiki.qt.io/Install_Qt_5_on_Ubuntu).

#### Docker

Para instalar o docker no ubuntu, atualize os pacotes e instale o pacote docker.io
```bash
sudo apt-get update
sudo apt-get install docker.io
```

Caso utilize uma distribuição de arch, utilize o comando abaixo
```bash
sudo pacman -Sy docker
```

Inicie o daemon
```bash
sudo systemctl start docker
```

Caso queira iniciar o docker sempre que o computador iniciar, ative o serviço na inicialização
```bash
sudo systemctl enable docker
```

Para testar a instalação, rode o seguinte comando:
```bash
docker --version
```
Obs: pode ser necessário utilizar sudo.


Para evitar utilizar sudo sempre, adicione seu usuário ao grupo do docker

Crie o grupo, caso não exista
```bash
sudo groupadd docker
```

Adicione o seu usuário ao grupo
```bash
sudo usermod -aG docker $USER
```

É necessário reiniciar o computador para reavaliar os grupos. Para ativar sem reiniciar(válido apenas na sessão atual do terminal), utilize o comando abaixo
```bash
newgrp docker
```

#### Docker compose

Para instalar o docker compose em uma distribuição arch, utilize o comando abaixo.
```bash
sudo pacman -Sy docker-compose
```

Caso utilize Ubuntu, siga os passos abaixo

Faça download do binário do docker compose na pasta /usr/local/bin
```bash
sudo curl -L "https://github.com/docker/compose/releases/download/1.23.1/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
```

Quando o download for concluído, altere as permissões do arquivo para executá-lo
```bash
sudo chmod +x /usr/local/bin/docker-compose
```

Teste a instalação utilizando o comando versão
```bash
docker-compose --version
```

### Ferramentas Adicionais e versões utilizadas

Foram utilizadas as seguintes ferramentas para a elaboração da documentação do projeto:
- Diagramas UML: Astah UML 8.1.0/3ac74f
- Modelo do Banco de Dados: MySQL Workbench 8.0.17
- Documentação do código: Doxygen 1.8.16


### Instalando

Uma série de exemplos passo a passo que ensinam a configurar um ambiente de desenvolvimento irão aqui.

Diga o que será o passo

```
Dê o exemplo
```

E repita

```
Até acabar
```

Termine com um exemplo de um teste rápido do sistema

## Rodando os testes

Para rodar os testes unitários, na barra inferior do QtCreator, abaixo dos logs, procure a opção "_8 Test Results_" e a selecione. Em seguida, clique no play verde para executar todos os testes.

Você deve ver em seguida o resultado da execução dos testes.

Caso deseje executar os testes unitários sem instalar o QtCreator, será necessário ter o Qt e o qmake instalados. Depois de instalá-los seguindo os passos na seção inicial desse README, siga os passos abaixo:

Primeiro, crie um diretório na raiz do projeto para a build e entre no diretório
```bash
mkdir build && cd build
```

Em seguida, rode a ferramenta de qmake para criar os makefiles
```bash
qmake ../test/test.pro
```

Depois do qmake terminar, rode make para compilar. No parâmetro j, ajuste o valor para o dobro de núcleos do seu processador.
```bash
make -j8 && make clean -j8
```

Em seguida, você pode acessar as pastas de cada teste e executar o teste como o seguinte exemplo para Cartao:
```bash
cd Cartao && ./testecartao
```

Pronto, você verá a saída dos testes no terminal.

### Escrevendo Testes Unitários

Utilizamos o framework QTest do Qt para automatizar os testes unitários utilizando testes dirigidos por dados. Para criar testes, adicione os testes como _slots_ na classe `Testes<CLASSE>` em que <CLASSE> deve ser substituído pela classe/funcionalidade a ser testada. O nome do arquivo que contém esta classe deverá ser idêntico ao dela, porém escrito com todas as letras minúsculas.
Essa classe deve estar em uma pasta com o nome <CLASSE> dentro da pasta test do projeto. Para o nome da pasta <CLASSE> deve ter a primeira letra maiúscula.

Além da classe de teste, devemos incluir um arquivo <CLASSE>.pro com o seguinte conteúdo(Todas as ocorrências de <CLASSE> são com letras minúsculas):

```
CONFIG += testcase
TARGET = teste<CLASSE>
QT = core testlib
SOURCES = \
     teste<CLASSE>.cpp \
     ../../src/<arquivos-a-serem-testados>.cpp
INCLUDEPATH += ../../src
```

Em seguida, abra o arquivo test/test.pro e adicione a seguinte linha logo abaixo do último _subdir_:

```
      <CLASSE> \
```

Para mais informações sobre como criar testes unitários dirigidos por dados, confira os tutoriais disponíveis em [QTest, criando testes unitários](https://doc.qt.io/qt-5/qttestlib-tutorial1-example.html) e [QTest, testes dirigidos por dados](https://doc.qt.io/qt-5/qttestlib-tutorial2-example.html#)


### E testes de estilo de código

Explicaremos o que é testado e porque

```
Dê um exemplo
```

## Deploy

Adicionaremos notas para deploy para produção conforme o trabalho for desenvolvido.

### Banco de Dados

Nosso banco de dados será executado em uma imagem do Docker no servidor local. O arquivo _docker-compose.yml_, junto com o _db/Dockerfile_ descrevem nosso container e contém todas as configurações necessárias. Caso queira alterar informações como usuário ou senha, edite a seção `environment` do arquivo docker-compose.yml como descrito abaixo:

```yaml
...
    environment:
        MYSQL_ROOT_PASSWORD: <sua-nova-senha-root>
        MYSQL_DATABASE: <seu-banco-de-dados>
        MYSQL_USER: <seu-novo-usuario>
        MYSQL_PASSWORD: <sua-nova-senha>
    volumes:
...
```

É possível alterar outras configurações como nome da imagem do container, local do Dockerfile, porta de conexão aberta para o banco e volume onde serão salvas as informações do banco.

## Ferramentas de build

* *qmake* - Disponibilizado pelo Qt
* *make*
* *docker* - Compila nosso Dockerfile

## Contribuindo

Para contribuir, siga os passos abaixo:

  1. Navegue até a aba de [issues](https://github.com/MatTerra/IngressoNet/issues) do github e verifique se já existe alguma entrada relativa à funcionalidade ou correção que você desenvolverá.
  1. Caso exista, adicione um comentário para avisar que você está trabalhando neste issue e, se possível, se adicione como responsável.
  1. Crie uma nova branch com um nome que remeta ao issue alvo utilizando o comando a seguir no diretório local do repositório `git checkout -b <nome>`
  1. Após terminar o desenvolvimento da funcionalidade e dos testes unitários, crie um [pull request](https://github.com/MatTerra/IngressoNet/pulls) e adicione na descrição dele um comentário sobre o que está sendo implementado e a seguinte frase: "_Closes #n_", onde n é o número do issue que você soluciona. Caso resolva mais de um issue, adicione um por linha com a mesma frase.
  1. Adicione ao menos dois membros do repositório que não trabalharam no pull request como revisores.

### Regras para aprovação do PR

  1. Desenvolva inicialmente os testes unitários, caso alguma funcionalidade tenha sido implementada. Visamos 100% de cobertura de testes.
  1. Siga nosso estilo de código, como descrito [aqui](https://github.com/twitter/commons/blob/master/src/java/com/twitter/common/styleguide.md)(O estilo utilizado é o estilo java).

## Versionamento

Usamos [SemVer](http://semver.org/) para versionamento. Para versões disponíveis, veja as [tags nesse repositório](https://github.com/MatTerra/IngressoNet/tags).

## Autores

* **Mateus Berardo** - *Autor* - [MatTerra](https://github.com/MatTerra)
* **Thiago Cardoso** - *Autor* - [ThiagoPais](https://github.com/ThiagoPais)
* **Bruno Murta** - *Autor* - [bruno-bmc](https://github.com/bruno-bmc)
Veja também a lista de [contribuidores](https://github.com/MatTerra/IngressoNet/contributors) que participaram nesse projeto.

## Licença

Esse projeto está licenciado sob uma licença do MIT - veja o arquivo [LICENSE.md](LICENSE.md) para detalhes

## Agradecimentos

* Thanks to **Billie Thompson** aka [PurpleBooth](https://github.com/PurpleBooth) who created the template of this README


