import xml.etree.ElementTree as ET

def sortElement(parent, attr):
     parent[:]=sorted(parent, key=lambda child:child.get(attr))

def recursion(element):
    # 子要素を持たない
    if not element:
        return

    #子要素を列挙
    taglist=[]
    for child in element:
        taglist.append(child.tag)
    taglist = list(set(taglist))

    for tag in taglist:
        target = element.find(tag)
        # 各子要素が子を持つ場合
        if target and len(target.attrib) != 0:
            # 最初の属性を用いてソートする
            attr = sorted(target.attrib.keys())[0]
            sortElement(element, attr)

    for child in element:
        recursion(child)


tree = ET.parse('test.xml')
recursion(tree.getroot())

gold = ET.parse('test.xml')
recursion(gold.getroot())
