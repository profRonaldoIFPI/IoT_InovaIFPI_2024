### Configuração do docker conpose com um container do *ThingsBoard*

Passoa a passo de acordo com a [documentação](https://thingsboard.io/docs/user-guide/install/docker-windows/) do *ThingsBoard*


Prerequisitos:
    - Docker Desktop instalado em seu computador com Windows;
    - Isso só é possível com WSL2 instalado e configurado em seu computador.

Configuração:

 - Criar os volumes onde serão gravados os dados e logs do container:
 Abra um terminal (cmd ou powershell) e execute os comandos abaixo:
 ```
 docker volume create mytb-data
 docker volume create mytb-logs 

 ```

 No diretório do seu projeto coloque ou crie o arquivo `docker-compose.yml`.
 Este arquivo contém as cofigurações da stack docker que será criada.
 Execute o comando abaixo:
 ```
 docker compose up -d
 docker compose logs -f mytb
 ```
 Na primeira execução o docker vai baixar a imagem do container e configura-lo de acordo com o arquivo `docker-compose.yml` e executa-lo em seguida. Os comandos acima executam o container e ativam os logs, respectivamente.

O *ThingsBoard* estará em execução com as seguintes portas disponíveis:

```
8080:9090 - conecte a porta local 8080 à porta HTTP interna exposta 9090
1883:1883 - conecte a porta local 1883 à porta MQTT interna exposta 1883
7070:7070 - conecte a porta local 7070 à porta Edge RPC interna exposta 7070
5683-5688:5683-5688/udp - conectar portas UDP locais 5683-5688 às portas COAP e LwM2M internas expostas
```
A interface web estará acessível em `localhost:8080`.

 O container está configurado os os usuários:
  - Administrador do sistema : **sysadmin@thingsboard.org / sysadmin**
  - Administrador do inquilino : **tenant@thingsboard.org / tenant**
  - Usuário cliente : **customer@thingsboard.org / customer**



 Você pode se desconectar do terminal de sessão usando `Ctrl-p Ctrl-q`a sequência de teclas - o contêiner continuará sendo executado em segundo plano.

Em caso de problemas, você pode examinar os logs de serviço para erros. Por exemplo, para ver os logs do contêiner ThingsBoard, execute o seguinte comando:

`docker compose logs -f mytb`

Para parar o contêiner:

`docker compose stop mytb` 

Para iniciar o contêiner:

`docker compose start mytb`

Para mais detalhes consulte a [documentação](https://thingsboard.io/docs/user-guide/install/docker-windows/).