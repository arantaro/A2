import matplotlib.pyplot as plt
import csv

from math import asin, pi


def get_cords(filename):
    X = []
    Y = []
    with open(filename, "r") as datafile:
        for row in csv.reader(datafile, delimiter=' '):
            X.append(float(row[0]))
            Y.append(float(row[1]))
    return X, Y


if __name__ == '__main__':

    for folder_name in ["random_array", "reversed_array", "almost_sorted_array"]:
        plt.plot(1, 1, 1)
        plt.title(folder_name)
        plt.xlabel("Array size")
        plt.ylabel("Microseconds")

        for switching_param, color in zip([1, 5, 15, 30, 50, 100],
                                          ['#1f77b4', '#ff7f0e', '#2ca02c', '#d62728', '#9467bd',
                                           '#8c564b']):
            filename = folder_name + "/switching_param = " + str(switching_param) + ".csv"
            X, Y = get_cords(filename)
            plt.plot(X, Y,
                     label="merge sort" if switching_param == 1
                     else f"hybrid sort, switching param = {switching_param}",
                     color=color)
        plt.legend()
        plt.savefig(folder_name + ".png")
        plt.show()

        # plt.tight_layout()
        # plt.savefig(folder_name + "/" + str(i + 1) + ".png")
        # plt.clf()
