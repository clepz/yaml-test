import yaml

class YamlReader(object):
    
    __data = None
    
    @staticmethod
    def load(yml_file):
        f = open(yml_file, "r")
        try:
            YamlReader.__data = yaml.safe_load(f)
            f.close()
        except yaml.YAMLError as exc:
            print(exc)
        
        for k, v in YamlReader.__data.items():
            if type(v) is dict:
                setattr(YamlReader, k, v)

    @staticmethod
    def getAll():
        return YamlReader.__data