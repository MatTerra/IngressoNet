# IngressoNet

IngressoNet é um modelo de sistema de venda de ingressos. O projeto está em desenvolvimento para a matéria Técnicas de Programação 1 do CIC/UnB. O sistema deve funcionar com uma arquitetura em camadas para vender ingressos para partidas locais, regionais, estaduais, nacionais e internacionais. OS usuários podem criar e administrar até 5 partidas simultaneamente e podem se descadastrar quando necessário, exceto enquanto administram alguma partida.

## Primeiros Passos

O sistema foi desenvolvido utilizando o framework Qt e depende de uma instalação do docker e docker-compose para execução. Veja as notas de deploy para instruções de como fazer o deploy do sistema para produção.

### Pré requisitos

#### Qt

O código foi desenvolvido utilizando o framework Qt 5, para instalá-lo no linux, acesse o [site oficial](https://www.qt.io/download#section-2) ou siga os passos abaixo(disponíveis em [Install Qt 5 on Ubuntu](https://wiki.qt.io/Install_Qt_5_on_Ubuntu)) para instalar pelo terminal. É recomendada a instalação do Qt creator por meio do download do site oficial.

Baixe o instalador
```
wget http://download.qt.io/official_releases/qt/5.7/5.7.0/qt-opensource-linux-x64-5.7.0.run
```

Forneça permissão para execução, execute o instalador e siga os passos para concluir a instalação
```
chmod +x qt-opensource-linux-x64-5.7.0.run
./qt-opensource-linux-x64-5.7.0.run
```

Instale o compilador g++
```
sudo apt-get update
sudo apt-get install build-essential
```

Caso você utilize alguma distribuição de arch, o comando para instalação do g++ será o seguinte.
```
sudo pacman -Sy base-devel
```

Isto deve ser o suficiente para iniciar o QtCreator. Caso seja necessário, configure o compilador, instale as bibliotecas de OpenGL e associe arquivos .pro ao QtCreator. Para mais informações, acesse a [documentação do Qt](https://wiki.qt.io/Install_Qt_5_on_Ubuntu).

#### Docker

Para instalar o docker no ubuntu, atualize os pacotes e instale o pacote docker.io
```
sudo apt-get update
sudo apt-get install docker.io
```

Caso utilize uma distribuição de arch, utilize o comando abaixo
```
sudo pacman -Sy docker
```

Inicie o daemon
```
sudo systemctl start docker
```

Caso queira iniciar o docker sempre que o computador iniciar, ative o serviço na inicialização
```
sudo systemctl enable docker
```

Para testar a instalação, rode o seguinte comando:
```
docker --version
```
Obs: pode ser necessário utilizar sudo.


Para evitar utilizar sudo sempre, adicione seu usuário ao grupo do docker

Crie o grupo, caso não exista
```
sudo groupadd docker
```

Adicione o seu usuário ao grupo
```
sudo usermod -aG docker $USER
```

É necessário reiniciar o computador para reavaliar os grupos. Para ativar sem reiniciar(válido apenas na sessão atual do terminal), utilize o comando abaixo
```
newgrp docker
```

#### Docker compose

Para instalar o docker compose em uma distribuição arch, utilize o comando abaixo.
```
sudo pacman -Sy docker-compose
```

Caso utilize Ubuntu, siga os passos abaixo

Faça download do binário do docker compose na pasta /usr/local/bin
```
sudo curl -L "https://github.com/docker/compose/releases/download/1.23.1/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
```

Quando o download for concluído, altere as permissões do arquivo para executá-lo
```
sudo chmod +x /usr/local/bin/docker-compose
```

Teste a instalação utilizando o comando versão
```
docker-compose --version
```

### Ferramentas Adicionais e versões utilizadas

Foram utilizadas as seguintes ferramentas para a elaboração da documentação do projeto:
- Diagramas UML: Astah UML 8.1.0/3ac74f
- Modelo do Banco de Dados: MySQL Workbench 8.0.17
- Documentação do código: Doxygen 


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

Explicaremos como rodar os testes automatizados para este sistema

### Quebre em teste de ponta a ponta

Explicaremos o que é testado e porque

```
Dê um exemplo
```

### E testes de estilo de código

Explicaremos o que é testado e porque

```
Dê um exemplo
```

## Deploy

Adicionaremos notas para deploy para produção

## Ferramentas de build

* [Qt 5](https://qt.io/) - O framework de desenvolvimento utilizado

## Contribuindo

Por favor leia [CONTRIBUTING.md]() para detalhes do nosso código de conduta e do processo de submissão de PR's para nós.

## Versionamento

Usamos [SemVer](http://semver.org/) para versionamento. Para versões disponíveis, veja as [tags nesse repositório](https://github.com/your/project/tags). 

## Autores

* **Mateus Berardo** - *Autor* - [MatTerra](https://github.com/MatTerra)
* **Thiago Pais** - *Autor* - [ThiagoPais](https://github.com/ThiagoPais)
* **Bruno Murta** - *Autor* - [bruno-bmc](https://github.com/bruno-bmc)
Veja também a lista de [contribuidores](https://github.com/your/project/contributors) que participaram nesse projeto.

## Licença

Esse projeto está licenciado sob uma licença do MIT - veja o arquivo [LICENSE.md](LICENSE.md) para detalhes

## Agradecimentos

* Thanks to **Billie Thompson** aka [PurpleBooth](https://github.com/PurpleBooth) who created the template of this README

