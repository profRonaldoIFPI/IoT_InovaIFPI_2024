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

 Você pode se desconectar do terminal de sessão usando `Ctrl-p Ctrl-q`a sequência de teclas - o contêiner continuará sendo executado em segundo plano.

Em caso de problemas, você pode examinar os logs de serviço para erros. Por exemplo, para ver os logs do contêiner ThingsBoard, execute o seguinte comando:

`docker compose logs -f mytb`

Para parar o contêiner:

`docker compose stop mytb` 

Para iniciar o contêiner:

`docker compose start mytb`

Para mais detalhes consulte a [documentação](https://thingsboard.io/docs/user-guide/install/docker-windows/).