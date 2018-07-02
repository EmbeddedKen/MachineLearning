from chatterbot import ChatBot
import os

bot = ChatBot("SS",
              read_only=True,
              storage_adapter='chatterbot.storage.SQLStorageAdapter',
              database='./db.sqlite3')

print(os.getcwd())

print('START')
while True:
              request = input('')
              response = bot.get_response(request)
              print(response)

              #request = input("")
              #print(bot.get_response(request).text)
