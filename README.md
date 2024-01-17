# cpp-mysql

Requires [Chalet](https://www.chalet-work.space/) to build. Only tested on Windows so far.

1. Install [MySQL Community Server](https://dev.mysql.com/downloads/mysql/) and make sure it's running
2. Add a `.env` in the project directory with the following:

```ini
SAPP_MYSQL_HOST=(host - blank if 127.0.0.1)
SAPP_MYSQL_PORT=(port - blank if 33060)
SAPP_MYSQL_USER=(user)
SAPP_MYSQL_PWD=(pwd)
SAPP_MYSQL_DB=(db)
```

3. Run `chalet buildrun` to build the application and run it
