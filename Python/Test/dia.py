import xml.etree.ElementTree as ET
from xml.dom import minidom

# Dữ liệu chi tiết Bài 1 (Cấu trúc rẽ nhánh sâu: Main -> Sub -> Detail)
lesson_1_detailed = {
    "title": "BÀI 1: PHƯƠNG PHÁP\nBIỂU HIỆN BẢN ĐỒ",
    "branches": [
        {
            "main": "1. Phương pháp Kí hiệu",
            "subs": [
                {"text": "Đối tượng biểu hiện", "details": ["Phân bố theo điểm cụ thể", "Ví dụ: Sân bay, nhà máy, mỏ khoáng sản"]},
                {"text": "Cách thể hiện", "details": ["Đặt kí hiệu chính xác vào vị trí phân bố"]},
                {"text": "Các dạng kí hiệu", "details": ["Hình học (tròn, vuông...)", "Chữ cái (Fe, Cu...)", "Tượng hình (hình máy bay, bông lúa)"]},
                {"text": "Khả năng biểu hiện", "details": ["Vị trí phân bố", "Số lượng & Quy mô", "Cấu trúc & Chất lượng"]}
            ]
        },
        {
            "main": "2. PP Đường chuyển động",
            "subs": [
                {"text": "Đối tượng biểu hiện", "details": ["Sự di chuyển trong không gian", "Ví dụ: Gió, bão, dòng biển", "Ví dụ: Luồng di dân, vận tải"]},
                {"text": "Cách thể hiện", "details": ["Dùng các mũi tên", "Độ dài/ngắn, dày/mảnh khác nhau"]},
                {"text": "Khả năng biểu hiện", "details": ["Hướng di chuyển", "Khối lượng (lớn/nhỏ)", "Tốc độ (nhanh/chậm)"]}
            ]
        },
        {
            "main": "3. PP Chấm điểm",
            "subs": [
                {"text": "Đối tượng biểu hiện", "details": ["Phân bố phân tán, không đều", "Ví dụ: Điểm dân cư", "Ví dụ: Cơ sở chăn nuôi"]},
                {"text": "Cách thể hiện", "details": ["Các điểm chấm", "Mỗi chấm có giá trị số lượng nhất định"]},
                {"text": "Khả năng biểu hiện", "details": ["Số lượng đối tượng", "Mức độ phân bố (dày/thưa)"]}
            ]
        },
        {
            "main": "4. PP Khoanh vùng",
            "subs": [
                {"text": "Đối tượng biểu hiện", "details": ["Không gian phân bố theo vùng", "Ví dụ: Vùng phân bố dân tộc", "Ví dụ: Vùng trồng lúa/chăn nuôi"]},
                {"text": "Cách thể hiện", "details": ["Đường viền giới hạn", "Tô màu / Chải nét (kẻ vạch)", "Bố trí kí hiệu đều đặn"]}
            ]
        },
        {
            "main": "5. PP Bản đồ - Biểu đồ",
            "subs": [
                {"text": "Đối tượng biểu hiện", "details": ["Giá trị tổng cộng của đối tượng", "Theo đơn vị lãnh thổ (tỉnh/huyện)"]},
                {"text": "Cách thể hiện", "details": ["Đặt biểu đồ vào phạm vi lãnh thổ", "Dạng: Cột, tròn, miền..."]},
                {"text": "Khả năng biểu hiện", "details": ["Quy mô (độ lớn)", "Cơ cấu (tỉ lệ)", "Phân bố không gian"]}
            ]
        }
    ]
}

def create_detailed_xml(data):
    mxfile = ET.Element('mxfile', host="app.diagrams.net")
    diagram = ET.SubElement(mxfile, 'diagram', name="Bai 1 Chi Tiet")
    mxGraphModel = ET.SubElement(diagram, 'mxGraphModel', dx="1500", dy="1500", grid="1", gridSize="10", guides="1", tooltips="1", connect="1", arrows="1", fold="1", page="1", pageScale="1", pageWidth="1169", pageHeight="827", math="0", shadow="0")
    root = ET.SubElement(mxGraphModel, 'root')
    
    ET.SubElement(root, 'mxCell', id="0")
    ET.SubElement(root, 'mxCell', id="1", parent="0")
    
    # Root Node
    root_id = "root_node"
    style_root = "ellipse;whiteSpace=wrap;html=1;fillColor=#dae8fc;strokeColor=#6c8ebf;fontStyle=1;fontSize=18;fontFamily=Helvetica;"
    root_cell = ET.SubElement(root, 'mxCell', id=root_id, value=data['title'], style=style_root, vertex="1", parent="1")
    
    center_x, center_y = 600, 400
    ET.SubElement(root_cell, 'mxGeometry', x=str(center_x), y=str(center_y), width="220", height="100", as="geometry")
    
    # Layout parameters
    branches = data['branches']
    num_branches = len(branches)
    # Phân bố hướng tâm (Radial layout simulation)
    # Để đơn giản, chia 3 bên trái, 2 bên phải
    left_branches = branches[:3]
    right_branches = branches[3:]
    
    branch_spacing_y = 350  # Khoảng cách dọc giữa các nhánh chính lớn hơn vì chi tiết nhiều
    
    # --- Xử lý nhánh TRÁI ---
    for i, branch in enumerate(left_branches):
        b_id = f"bL_{i}"
        b_x = center_x - 350
        b_y = 100 + (i * branch_spacing_y)
        
        # Nhánh chính cấp 1
        style_branch = "rounded=1;whiteSpace=wrap;html=1;fillColor=#d5e8d4;strokeColor=#82b366;fontStyle=1;fontSize=14;"
        ET.SubElement(root, 'mxCell', id=b_id, value=branch['main'], style=style_branch, vertex="1", parent="1").append(
            ET.Element('mxGeometry', x=str(b_x), y=str(b_y), width="200", height="60", as="geometry")
        )
        # Nối Root -> Nhánh chính
        ET.SubElement(root, 'mxCell', id=f"eL_{i}", style="edgeStyle=orthogonalEdgeStyle;rounded=1;html=1;entryX=1;entryY=0.5;exitX=0;exitY=0.5;strokeWidth=2;", edge="1", parent="1", source=root_id, target=b_id).append(
            ET.Element('mxGeometry', relative="1", as="geometry")
        )
        
        # Nhánh phụ cấp 2 (Sub)
        for j, sub in enumerate(branch['subs']):
            s_id = f"sL_{i}_{j}"
            s_x = b_x - 250
            s_y = b_y - 60 + (j * 80) # Dàn trải dọc
            
            style_sub = "rounded=1;whiteSpace=wrap;html=1;fillColor=#fff2cc;strokeColor=#d6b656;fontStyle=1;"
            ET.SubElement(root, 'mxCell', id=s_id, value=sub['text'], style=style_sub, vertex="1", parent="1").append(
                ET.Element('mxGeometry', x=str(s_x), y=str(s_y), width="180", height="40", as="geometry")
            )
            # Nối Nhánh chính -> Nhánh phụ
            ET.SubElement(root, 'mxCell', id=f"esL_{i}_{j}", style="edgeStyle=orthogonalEdgeStyle;rounded=1;html=1;entryX=1;entryY=0.5;exitX=0;exitY=0.5;", edge="1", parent="1", source=b_id, target=s_id).append(
                ET.Element('mxGeometry', relative="1", as="geometry")
            )
            
            # Nhánh chi tiết cấp 3 (Detail)
            for k, detail in enumerate(sub['details']):
                d_id = f"dL_{i}_{j}_{k}"
                d_x = s_x - 220
                d_y = s_y + (k * 30) - 10 # Dàn trải dọc nhỏ
                
                style_detail = "text;html=1;strokeColor=none;fillColor=none;align=left;verticalAlign=middle;whiteSpace=wrap;rounded=0;"
                ET.SubElement(root, 'mxCell', id=d_id, value=f"- {detail}", style=style_detail, vertex="1", parent="1").append(
                    ET.Element('mxGeometry', x=str(d_x), y=str(d_y), width="200", height="20", as="geometry")
                )
                # Nối Phụ -> Chi tiết
                ET.SubElement(root, 'mxCell', id=f"edL_{i}_{j}_{k}", style="edgeStyle=orthogonalEdgeStyle;rounded=0;html=1;entryX=1;entryY=0.5;exitX=0;exitY=0.5;dashed=1;", edge="1", parent="1", source=s_id, target=d_id).append(
                    ET.Element('mxGeometry', relative="1", as="geometry")
                )

    # --- Xử lý nhánh PHẢI ---
    for i, branch in enumerate(right_branches):
        b_id = f"bR_{i}"
        b_x = center_x + 350
        b_y = 250 + (i * branch_spacing_y)
        
        # Nhánh chính cấp 1
        style_branch = "rounded=1;whiteSpace=wrap;html=1;fillColor=#d5e8d4;strokeColor=#82b366;fontStyle=1;fontSize=14;"
        ET.SubElement(root, 'mxCell', id=b_id, value=branch['main'], style=style_branch, vertex="1", parent="1").append(
            ET.Element('mxGeometry', x=str(b_x), y=str(b_y), width="200", height="60", as="geometry")
        )
        # Nối Root -> Nhánh chính
        ET.SubElement(root, 'mxCell', id=f"eR_{i}", style="edgeStyle=orthogonalEdgeStyle;rounded=1;html=1;entryX=0;entryY=0.5;exitX=1;exitY=0.5;strokeWidth=2;", edge="1", parent="1", source=root_id, target=b_id).append(
            ET.Element('mxGeometry', relative="1", as="geometry")
        )
        
        # Nhánh phụ cấp 2 (Sub)
        for j, sub in enumerate(branch['subs']):
            s_id = f"sR_{i}_{j}"
            s_x = b_x + 250
            s_y = b_y - 60 + (j * 80)
            
            style_sub = "rounded=1;whiteSpace=wrap;html=1;fillColor=#fff2cc;strokeColor=#d6b656;fontStyle=1;"
            ET.SubElement(root, 'mxCell', id=s_id, value=sub['text'], style=style_sub, vertex="1", parent="1").append(
                ET.Element('mxGeometry', x=str(s_x), y=str(s_y), width="180", height="40", as="geometry")
            )
            # Nối Nhánh chính -> Nhánh phụ
            ET.SubElement(root, 'mxCell', id=f"esR_{i}_{j}", style="edgeStyle=orthogonalEdgeStyle;rounded=1;html=1;entryX=0;entryY=0.5;exitX=1;exitY=0.5;", edge="1", parent="1", source=b_id, target=s_id).append(
                ET.Element('mxGeometry', relative="1", as="geometry")
            )
            
            # Nhánh chi tiết cấp 3 (Detail)
            for k, detail in enumerate(sub['details']):
                d_id = f"dR_{i}_{j}_{k}"
                d_x = s_x + 200
                d_y = s_y + (k * 30) - 10
                
                style_detail = "text;html=1;strokeColor=none;fillColor=none;align=left;verticalAlign=middle;whiteSpace=wrap;rounded=0;"
                ET.SubElement(root, 'mxCell', id=d_id, value=f"- {detail}", style=style_detail, vertex="1", parent="1").append(
                    ET.Element('mxGeometry', x=str(d_x), y=str(d_y), width="200", height="20", as="geometry")
                )
                # Nối Phụ -> Chi tiết
                ET.SubElement(root, 'mxCell', id=f"edR_{i}_{j}_{k}", style="edgeStyle=orthogonalEdgeStyle;rounded=0;html=1;entryX=0;entryY=0.5;exitX=1;exitY=0.5;dashed=1;", edge="1", parent="1", source=s_id, target=d_id).append(
                    ET.Element('mxGeometry', relative="1", as="geometry")
                )

    return ET.tostring(mxfile, encoding='utf-8')

# Tạo và lưu file
xml_content = create_detailed_xml(lesson_1_detailed)
reparsed = minidom.parseString(xml_content)
pretty_xml = reparsed.toprettyxml(indent="  ")

with open("Bai1_SieuChiTiet.xml", "w", encoding="utf-8") as f:
    f.write(pretty_xml)

print("Đã tạo xong file: Bai1_SieuChiTiet.xml. Bạn hãy tải về và mở trên draw.io nhé!")