GREEN := "\033[32m"
YELLOW := "\033[33m"
BLUE := "\033[34m"
NC := "\033[0m"

all: hosts
	@mkdir -p /home/joonhan/data/mysql
	@mkdir -p /home/joonhan/data/wordpress
	@mkdir -p /home/joonhan/data/nextjs
	@docker compose -f ./srcs/docker-compose.yml up -d --build

dev:
	@mkdir -p ./data/mysql
	@mkdir -p ./data/wordpress
	@mkdir -p ./data/nextjs
	@docker compose -f ./srcs/docker-compose.yml up -d --build

up:
	@docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	@rm -rf ./data/mysql/* ./data/wordpress/* ./data/nextjs/*
	@docker compose -f ./srcs/docker-compose.yml down

re: prune
	make all

stop:
	@if [ $$(docker ps -q | wc -l) -gt 0 ]; then \
		echo ${BLUE}"Stopping containers..."${NC}; \
		docker stop $$(docker ps -q); \
	else \
		echo ${YELLOW}"No running containers found."${NC}; \
	fi

prune: stop
	@echo ${BLUE}"docker system prune will be executed"${NC}; \
	sudo docker system prune -a -f --volumes
	@echo ${BLUE}"Bind mounted volumes will be deleted"${NC};
	@sudo rm -rf /home/joonhan/data/mysql
	@sudo rm -rf /home/joonhan/data/wordpress

hosts:
	@if grep -qxF '127.0.0.1 joonhan.42.fr' /etc/hosts; then \
		echo ${YELLOW}"Host entry already exists in /etc/hosts"${NC}; \
	else \
		echo '127.0.0.1 joonhan.42.fr' | sudo tee -a /etc/hosts; \
		echo ${GREEN}"Host entry added to /etc/hosts"${NC}; \
	fi
