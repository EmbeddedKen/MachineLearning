from chatterbot import ChatBot
from chatterbot.trainers import ChatterBotCorpusTrainer

chatterbot = ChatBot("Train")
chatterbot.set_trainer(ChatterBotCorpusTrainer)

#chatterbot.train( "./chatterbot-corpus/chatterbot_corpus/data/custom/myown.yml" )
chatterbot.train( "./myown.yml" )
