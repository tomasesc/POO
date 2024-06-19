from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
from pymongo import MongoClient

client = MongoClient('mongodb://localhost:27017/')
db = client.Usuarios

class Usuario(BaseModel):
    usuario: str
    clave: str

app = FastAPI()

@app.post("/validar_usuario")
async def validar_usuario(usuario: Usuario):
    usuario_db = db.usuario.find_one({"usuario": usuario.usuario, "clave": usuario.clave})  # Acceso a la colección usuario
    if not usuario_db:
        return "denegado"
    else:
        nombre_apellido = f"{usuario_db['nombre']}::{usuario_db['apellido']}"
        return nombre_apellido