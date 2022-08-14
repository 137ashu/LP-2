import tkinter

root = tkinter.Tk()

root.title("Chat Bot")
root.geometry("600x500")
root.resizable(width=False, height=False)
root.configure(background='#363636')


entry = tkinter.Entry(
    root, width=37, font="Helvetica 15 bold", bg='#202020', fg='cyan')
entry.place(x=30, y=50)


name = "Bot Number 286"
monsoon = "rainy"
mood = "Happy"
MovieH = "Bahubali 2"
MovieE = "Avenger : Endgame"
Fare = 500
location = "I am send you link for Cinema halls near you"
map = "https: // www.google.com/search?tbs = lf: 1, lf_ui: 1 & tbm = lcl & q = cinema+halls+near+me & rflfq = 1 & num = 10 & biw = 1294 & bih = 668 & dpr = 1"
resp = {
    "what's your name?": "\nBot :They call me {0}".format(name),
    "name": "\nBot :They call me {0}".format(name),
    "what's today's weather?": "\nBot :The weather is {0}".format(monsoon),
    "monsoon": "\nBot :The weather is {0}".format(monsoon),
    "how are you?": "\nBot :I am feeling {0}".format(mood),
    "how are": "\nBot :I am fine! and You",
    "": "\nBot :Hey! Are you there?",
    "yes": "\nBot :How can help you?",
    "which hindi movie going on": "\nBot :Now the {0} going on".format(MovieH),
    "hindi movie": "\nBot :Now the {0} going on".format(MovieH),
    "which english movie going on": "\nBot :Now the {0} going on".format(MovieE),
    "what is the ticket price": "\nBot :Ticket is {0}".format(Fare),
    "ticket": "\nBot :Ticket is {0}".format(Fare),
    "fare": "\nBot :Ticket is {0}".format(Fare),
    "cinemahall location": "\nBot :{0}\n link as following\n{1}".format(location, map),
    "location": "\nBot :{0}{1}".format(location, map),
}


def send_message(message):
    print((message))
    response = resp[message]
    print(response)
    return response


'''while 1:
    my_input = input()
    user = my_input.lower()
    #related_text = real(user)
    send_message(user)
    if my_input == "exit" or my_input == "stop":
        break'''


def chat():
    send = "\n\nYou : "+entry.get()
    txt.insert(tkinter.END, send)
    user = entry.get().lower()
    if(user == "hello"):
        txt.insert(
            tkinter.END, "\nBot : Hi I am bot, Welcome in Online Movie ticket Chatbot System,How can help you")
    elif(user == "hi" or user == "hii" or user == "hiiii"):
        txt.insert(
            tkinter.END, "\nBot : Hello I am bot, Welcome in Movie ticket Chatbot System,How can help you")
    elif(user == "fine" or user == "i am good" or user == "i am doing good"):
        txt.insert(tkinter.END, "\nBot : Great! how can I help you.")
    else:
        if resp.get(user) is not None:
            data = send_message(user)
            txt.insert(tkinter.END, data)
        else:
            txt.insert(
                tkinter.END, "\nBot : Sorry! I dind't got you please visit www.abc.com")
    entry.delete(0, tkinter.END)


btn = tkinter.Button(root, text="Send", width=10,
                     command=chat, bg='cyan', fg='black', font="Helvetica 10 bold")
btn.place(x=460, y=50)


txt = tkinter.Text(root, width=55, height=18,
                   font="Helvetica 13 bold", bg='#202020', fg='cyan')
txt.bind("<Key>", lambda a: "break")
txt.place(x=20, y=130)

root.mainloop()
