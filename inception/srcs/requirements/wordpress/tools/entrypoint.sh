#!/bin/sh

# Update WP-CLI to the latest stable release.
wp cli update

# Download and extracts WordPress core files to the specified path.
wp core download --allow-root --path="$WP_PATH"

# Generates a wp-config.php file.
wp config create --dbname="$MARIA_DB_DATABASE" --dbuser="$MARIA_DB_USER" \
				 --dbpass="$MARIA_DB_PASSWORD" --dbhost="$MARIA_DB_HOST" \
				 --path="$WP_PATH"

# Creates the WordPress tables in the database using the URL, title, and default admin user details provided
wp core install --allow-root --url="$WP_DOMAIN" --title="$WP_TITLE" \
				--admin_user="$WP_ADMIN_USER" --admin_password="$WP_ADMIN_PWD" \
				--admin_email="$WP_ADMIN_EMAIL" --skip-email --path="$WP_PATH"

# Creates a new user
wp user create "$WP_USER" "$WP_USER_EMAIL" --user_pass="$WP_USER_PWD" \
				--path="$WP_PATH"
	
# Set ownership of WordPress files to www-data
adduser -D -S -G www-data www-data
chown -R www-data:www-data /var/www/html/wordpress

# Execute PHP FastCGI in foreground
php-fpm8 -F
