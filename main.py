
from YamlLoader import YamlReader

if __name__ == "__main__":

    YamlReader.load("params.yaml")
    data = YamlReader.getAll()
    print YamlReader.params["name"]

    