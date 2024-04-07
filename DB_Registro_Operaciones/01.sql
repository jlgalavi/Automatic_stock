CREATE TABLE envio (
	id_envio serial primary key,
	id_pedido int not null, --clave foránea
	fecha_envio date not null,
	fecha_entrega date not null,
	costo_envio numeric(10, 2),
	estado varchar(50) not null
)
select * from pedido;
select * from envio;
select * from tipos_caja;
select * from estados_envios_entregados;

ALTER TABLE pedido
RENAME COLUMN tipo_caja TO tipos_caja;

ALTER TABLE pedido
ADD estado varchar(50) not null;

alter table envio
add constraint fk_pedido_id
foreign key (id_pedido)
references pedido(id_pedido);

create table tipos_caja(
	S varchar(2),
	M varchar(2),
	L varchar(2),
	XL varchar(3)
);

alter table pedido
alter column tipos_caja type varchar(3);

alter table pedido
add constraint tipos_caja_check check (tipos_caja in('S', 'M', 'L', 'XL'));

drop table tipos_caja;

create table estados_envios_entregados(
	id_envio int not null,
	estado_envio varchar(10) not null,
	descripcion_ocurrido varchar(255)
)

alter table estados_envios_entregados
add constraint id_envio_relacion
foreign key (id_envio)
references envio(id_envio);

alter table estados_envios_entregados
add constraint estado_envios check (estado_envio in('correcto', 'embajale dañado', 'producto dañado', 'ambos'));

alter table estados_envios_entregados
alter column estado_envio type varchar(20);

alter table estados_envios_entregados
add column contenedores_totales integer,
add column cajas_totales integer,
add column info_contenedores JSONB;

-- Ejemplo de inserción de datos en la columna info_contenedores
--UPDATE Envio
--SET info_contenedores = '{"numero_cajas": 10, "tipo_contenedor": "XL"}'
--WHERE id_envio = <id_del_envio>;