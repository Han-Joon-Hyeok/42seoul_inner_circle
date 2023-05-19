# Create wordpress database and mariadb user
cat << EOF > setting.sql
FLUSH PRIVILEGES;
CREATE DATABASE $MARIA_DB_DATABASE CHARACTER SET utf8 COLLATE utf8_general_ci;
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MARIA_DB_ROOT_PASSWORD';
CREATE USER '$MARIA_DB_USER'@'%' IDENTIFIED by '$MARIA_DB_PASSWORD';
GRANT ALL PRIVILEGES ON $MARIA_DB_DATABASE.* TO '$MARIA_DB_USER'@'%';
FLUSH PRIVILEGES;
EOF

# sql 실행 후 /var/lib/mysql/wordpress 폴더 생성
mysqld --bootstrap < setting.sql

rm -f setting.sql

# /var/lib/mysql/wordpress 폴더 권한을 root 에서 mysql 로 변경해주어야 permission denied 해결
chown -R mysql:mysql /run/mysqld /var/lib/mysql

mysqld --user=mysql --datadir=/var/lib/mysql --console
