FROM node:latest

WORKDIR /app

COPY package.json package-lock.json ./

RUN npm ci

COPY . .

RUN npm run build

RUN mkdir -p /nextjs_static && cp -r out/* /nextjs_static/
