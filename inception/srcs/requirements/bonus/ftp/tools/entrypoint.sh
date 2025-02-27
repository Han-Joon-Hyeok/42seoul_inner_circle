#!/bin/sh

# Create a user list for vsftpd
echo "ftpuser" > /etc/vsftpd/user_list

# Start vsftpd server
vsftpd /etc/vsftpd/vsftpd.conf
