from tkinter import *

root = Tk()
root.title("Tube - Transport for London")


def getInputs():
    pass
    # print(
    #     f"{source_value.get(), destination_value.get()} ")
    # p.Graph().findRoute(source_value.get(), destination_value.get())


root.geometry("600x200")
root.maxsize(600, 200)
root.minsize(600, 200)
root.resizable(0, 0)
Label(root, text="Welcome to London Tube Network", font="comicsansms 20 bold", pady=15).grid(row=0, column=3)
Label(root, text="Source Station:        ").grid(row=3, column=2)
Label(root, text="Destination Station: ").grid(row=4, column=2)

source_value = StringVar()
destination_value = StringVar()

source_entry = Entry(root, textvariable=source_value)
destination_entry = Entry(root, textvariable=destination_value)

source_entry.grid(row=3, column=3)
destination_entry.grid(row=4, column=3)
Button(text="Get Route", command=getInputs).grid(row=9, column=3)
Button(text="Quit", command=root.destroy).grid(row=11, column=3)

root.mainloop()